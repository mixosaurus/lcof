#include "Solution.h"
#include<iostream>
using namespace std;

bool Solution::findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
    for (auto line : matrix) {
        if(line.empty()){
            return false;
        }
        if (target < line.front()) {
            break;
        }
        if (containsTarget(line, target)) {
            return true;
        } else {
            continue;
        }      
    }
    return false;
}

bool Solution::containsTarget(vector<int>& nums, int target) {
    int low = 0;
    int high = nums.size()-1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (target==nums[mid]) {
            return true;
        } else if (target > nums[mid]) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return false;
}
