#include <iostream>
#include <vector>
#include <utility>
#include "Solution.h"
using namespace std;

int main() {
    Solution solution;
    vector<vector<char>> board = { 
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };
    cout << boolalpha << solution.exist(board, "ABCCEDFS");
    return 0;
}
