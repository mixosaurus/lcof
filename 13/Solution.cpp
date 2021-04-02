#include "Solution.h"
#include <iostream>
using namespace std;

int Solution::movingCount(int m, int n, int k) {
	this->m = m-1;
	this->n = n-1;
	movingCountRecursion(0,0,new vector<coordinate>(),k);
	return steps;
}

// �ֽ���λ���������
int Solution::getIndexTotal(int p) {
    int total_index = 0;
    while(p){
        total_index = total_index + p % 10;
		p=p/10;
	}
	return total_index;
}

//�ݹ麯��
void Solution::movingCountRecursion(int i, int j, vector<coordinate>* track, int k) {
	if (i<0 || i>m || j<0 || j>n) {
		return;
	}
	coordinate coord = { i,j };
	if (find(track->begin(), track->end(), coord) != track->end()) {
		return;
	}
    int total_i = getIndexTotal(i);
    int total_j = getIndexTotal(j);
	if (total_i + total_j > k) {
		return;
	}
	//�ѵ�ǰ�������·����
	coordinate coord2 = { i, j };
	track->push_back(coord2);
	steps++;
	// ����DFS�㷨�����ԣ�ֻ�������º���������·������
	movingCountRecursion(i+1,j,track,k);	//��
	movingCountRecursion(i,j+1,track,k);	//��
}
