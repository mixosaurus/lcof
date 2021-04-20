#include "Solution.h"
#include <iostream>
using namespace std;

int Solution::sumNums(int n) {
	(n > 0) && (n = n + sumNums(n - 1));
	return n;
}
