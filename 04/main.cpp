#include <iostream>
#include "Solution.h"
using namespace std;

int main(){
    Solution solution;
    vector<vector<int>> matrix = {
        {1,4,7,11,15},
        {2,5,8,12,19},
        {3,6,9,16,22},
        {10,13,14,17,24},
        {18,21,23,26,30}
    };
    cout<< boolalpha<<solution.findNumberIn2DArray(matrix,4);
    return 0;
}
