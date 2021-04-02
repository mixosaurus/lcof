#pragma once
#include <vector>
#include <string>

using namespace std;

struct coordinate {
	int x;
	int y;
	bool operator == (const coordinate &c){
        return (this->x == c.x) && (this->y ==c.y);
    }
};

class Solution {
private:
	int m;
	int n;
	// �ɴﲽ��
	// �Գ�Ա������ʽ���壬�����ڵݹ麯���䴫��
	int steps = 0;
public:
	int movingCount(int m, int n, int k);
	int getIndexTotal(int index);
	void movingCountRecursion(int i, int j, vector<coordinate>* track, int k);
};

