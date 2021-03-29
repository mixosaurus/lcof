#pragma once
#include <vector>
#include <string>

using namespace std;

struct coordinate {
	int x;
	int y;
	bool operator == (const coordinate &e){
        return (this->x == e.x) && (this->y ==e.y);
    }
};

class Solution {
private:
	int rows;
	int cols;
public:
	bool exist(vector<vector<char>>& board, string word);
	bool nextExist(vector<vector<char>>& board, int i, int j, vector<coordinate> track, string str,int k);
};

