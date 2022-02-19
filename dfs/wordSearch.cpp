#include <iostream>
#include <vector>
#include<algorithm>
#include <limits>
#include <unordered_map>
#include <cstdint>
using namespace std;
bool dfs(vector<vector<char>>& board, int index, pair<int, int> coor, string word);

bool exist(vector<vector<char>>& board, string word) {
        
        bool result = false;
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                if(board[i][j] == word[0] && dfs(board, 0, make_pair(i, j), word)) {
                    return true;
                    }  
                }
            }
        return result;
    }
    
bool dfs(vector<vector<char>>& board, int index, pair<int, int> coor, string word){
		if(index == word.size()) return true; 
        int row = coor.first;
        int col = coor.second;
        if(row < 0 || col < 0 || row >= board.size() || col >= board[row].size() || board[row][col] != word[index]) return false;
		auto up = make_pair(row - 1, col);
        auto down = make_pair(row + 1, col);
        auto left =  make_pair(row, col - 1);
        auto right =  make_pair(row, col + 1);
        
		//bool result = false;
		char temp = board[row][col];
		board[row][col] = '@';
        bool result =  dfs(board, index + 1,   up, word)
					|| dfs(board, index + 1, down, word)
					|| dfs(board, index + 1, left, word)
					|| dfs(board, index + 1,right, word);
       
		board[row][col] = temp;
        return result;
 
}



int main (){

	//vector<vector<char>> board {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
	vector<vector<char>> board {{'C','A','A'},{'A','A','A'},{'B','C','D'}};
	bool res = exist(board, "AAB");

	cout << res  << endl;


	return 0;
}

