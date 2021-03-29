#include "Solution.h"
#include <iostream>
#include <algorithm>   

using namespace std;

bool Solution::exist(vector<vector<char>>& board, string word) {
	rows = board.size();
    cols = board[0].size();
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (board[i][j] == word[0]) {
				if (nextExist(board, i, j, *(new vector<coordinate>()), word,0)) {
					return true;
				}
			}
		}
	}
	return false;
}

bool Solution::nextExist(vector<vector<char>>& board,int i, int j, vector<coordinate> track, string word,int k) {
	if (i>=rows|| i < 0||j>=cols||j<0|| board[i][j] != word[k]){
		return false;
	}
	coordinate coord = { i,j };
	if(find(track.begin(), track.end(),coord)!=track.end()){
		return false;
	}
	if (k == word.size() - 1) {
		return true;
	}
	coordinate coord2 = { i, j };
	track.push_back(coord2);
	return  nextExist(board, i - 1, j, track, word,k+1)||
			nextExist(board, i + 1, j, track, word,k+1)||
			nextExist(board, i, j - 1, track, word,k+1)||
			nextExist(board, i, j + 1, track, word,k+1);
}
