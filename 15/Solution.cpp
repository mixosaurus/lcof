#include "Solution.h"
#include <iostream>
#include <bitset>

using namespace std;

int Solution::hammingWeight(uint32_t n) {
	//初始状态下，把每一位作为一组，每一组的汉明重量为该位的值
	//之后分别将2、4、8、16位作为一组
	//每次分组后，该组的汉明重量即上次所分的对应两组的汉明重量之和
	n = (n & 0x55555555) + ((n >> 1) & 0x55555555);
	n = (n & 0x33333333) + ((n >> 2) & 0x33333333);
	n = (n & 0x0f0f0f0f) + ((n >> 4) & 0x0f0f0f0f);
	n = (n & 0x00ff00ff) + ((n >> 8) & 0x00ff00ff);
	n = (n & 0x0000ffff) + ((n >> 16) & 0x0000ffff);
	return n;
}

