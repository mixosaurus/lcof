#include "Solution.h"
#include <iostream>
#include <algorithm>   

using namespace std;

bool Solution::exist(vector<vector<char>>& board, string word) {
	rows = board.size();
    cols = board[0].size();
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			//数组第一个元素与目标字符串第一个元素相同才进入递归函数
			if (board[i][j] == word[0]) {
				if (nextExist(board, i, j, *(new vector<coordinate>()), word,0)) {
					return true;
				}
			}
		}
	}
	return false;
}

//track保存已经过的路径坐标
bool Solution::nextExist(vector<vector<char>>& board,int i, int j, vector<coordinate> track, string word,int k) {
	if (i>=rows|| i < 0||j>=cols||j<0){
		return false;
	}
	//当前坐标元素是否为目标字符串中的相应元素
	if (board[i][j] != word[k]){
		return false;
	}
	//检查当前坐标是否存在于已经过路径中
	coordinate coord = { i,j };
	if(find(track.begin(), track.end(),coord)!=track.end()){
		return false;
	}
	if (k == word.size() - 1) {
		return true;
	}
	//把当前坐标加入路径中
	coordinate coord2 = { i, j };
	track.push_back(coord2);
	return  nextExist(board, i - 1, j, track, word,k+1)||
			nextExist(board, i + 1, j, track, word,k+1)||
			nextExist(board, i, j - 1, track, word,k+1)||
			nextExist(board, i, j + 1, track, word,k+1);
}
