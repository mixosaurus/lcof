#include "Solution.h"
#include <iostream>
#include <bitset>

using namespace std;

int Solution::hammingWeight(uint32_t n) {
	//��ʼ״̬�£���ÿһλ��Ϊһ�飬ÿһ��ĺ�������Ϊ��λ��ֵ
	//֮��ֱ�2��4��8��16λ��Ϊһ��
	//ÿ�η���󣬸���ĺ����������ϴ����ֵĶ�Ӧ����ĺ�������֮��
	n = (n & 0x55555555) + ((n >> 1) & 0x55555555);
	n = (n & 0x33333333) + ((n >> 2) & 0x33333333);
	n = (n & 0x0f0f0f0f) + ((n >> 4) & 0x0f0f0f0f);
	n = (n & 0x00ff00ff) + ((n >> 8) & 0x00ff00ff);
	n = (n & 0x0000ffff) + ((n >> 16) & 0x0000ffff);
	return n;
}
