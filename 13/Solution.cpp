#include "Solution.h"
#include <iostream>
using namespace std;

int Solution::movingCount(int m, int n, int k) {
	this->m = m-1;
	this->n = n-1;
	movingCountRecursion(0,0,new vector<coordinate>(),k);
	return steps;
}

// 分解数位并计算其和
int Solution::getIndexTotal(int p) {
    int total_index = 0;
    while(p){
        total_index = total_index + p % 10;
		p=p/10;
	}
	return total_index;
}

//递归函数
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
	//把当前坐标加入路径中
	coordinate coord2 = { i, j };
	track->push_back(coord2);
	steps++;
	// 由于DFS算法的特性，只保留向下和向右两条路径即可
	movingCountRecursion(i+1,j,track,k);	//下
	movingCountRecursion(i,j+1,track,k);	//右
}
