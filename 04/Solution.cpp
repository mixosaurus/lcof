#include "Solution.h"
#include<iostream>
using namespace std;

bool Solution::findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
    for (auto line : matrix) {
        if (target < line.front()) {
            break;
        }
        for (auto i : line) {
            cout << i << " ";
        }
        cout << endl;
    }
    return false;
}
