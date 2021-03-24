#include "Solution.h"
#include<iostream>
using namespace std;

//当前索引(i, j)元素与target的大小关系有三种：等于、小于、大于
//若等于，返回
//若target小于当前元素，排除该列
//若target大于当前元素，排除该行
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
        //若target小于当前元素，该列剩余元素中不可能有目标值，需要排除该列，即索引左移
        //左移过程中j可能为负
        while (j>0 && target<matrix[i][j]) {
            j--;
        }
        //左移结束后如不再次判断可能错过目标元素
        if (matrix[i][j]==target) {
            return true;
        }
        i++;
        //以上while循环退出后，targrt大于当前元素，该行剩余元素中不可能有目标值，需要排除该行，即索引下移
    }
    return false;
}
