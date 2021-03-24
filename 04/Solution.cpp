#include "Solution.h"
#include<iostream>
using namespace std;

//��ǰ����(i, j)Ԫ����target�Ĵ�С��ϵ�����֣����ڡ�С�ڡ�����
//�����ڣ�����
//��targetС�ڵ�ǰԪ�أ��ų�����
//��target���ڵ�ǰԪ�أ��ų�����
bool Solution::findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
    if (matrix.empty() || matrix.front().empty()) {
        return false;
    }
    int i = 0;
    int j = matrix.front().size()-1;
    int rowCounts = matrix.size();
    while (i<rowCounts) {
        if (matrix[i][j]==target) {
            return true;
        }
        //��targetС�ڵ�ǰԪ�أ�����ʣ��Ԫ���в�������Ŀ��ֵ����Ҫ�ų����У�����������
        //���ƹ�����j����Ϊ��
        while (j>0 && target<matrix[i][j]) {
            j--;
        }
        //���ƽ������粻�ٴ��жϿ��ܴ��Ŀ��Ԫ��
        if (matrix[i][j]==target) {
            return true;
        }
        i++;
        //����whileѭ���˳���targrt���ڵ�ǰԪ�أ�����ʣ��Ԫ���в�������Ŀ��ֵ����Ҫ�ų����У�����������
    }
    return false;
}
