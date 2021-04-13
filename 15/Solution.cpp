#include "Solution.h"
#include <iostream>
#include <bitset>

using namespace std;

int Solution::hammingWeight(uint32_t n) {
	//未优化过的SWAR算法
	//初始状态下，把每一位作为一组，每一组的汉明重量为该位的值
	//之后分别将2、4、8、16位作为一组
	//每次分组后，该组的汉明重量即上次所分的对应两组的汉明重量之和
	n = (n & 0x55555555) + ((n >> 1) & 0x55555555);
	n = (n & 0x33333333) + ((n >> 2) & 0x33333333);
	n = (n & 0x0f0f0f0f) + ((n >> 4) & 0x0f0f0f0f);
	//此时整个序列已被分割位4组，每组长度为8
	//将4个组直接相加到最左8位
	n = (n << 24) + (n << 16) + (n << 8) + n;
	//取左侧8位
	n = n >> 24;
	return n;
}

