#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <unordered_map>
#include <cstdint>
using namespace std;
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<int>> rowVec(9, vector<int>(10, 0));
        vector<vector<int>> colVec(9, vector<int>(10, 0));
        vector<vector<int>> gridVec(9, vector<int>(10, 0));
        
        for(int i = 0; i < 9; ++i) {
            for(int j = 0; j < 9; ++j){
                if(board[i][j] != '.'){
                    int digit  = board[i][j] - '0';
                    int gridIdx = i / 3 * 3 + j / 3;
                    if(rowVec[i][digit] != 0 || colVec[j][digit] != 0 || gridVec[gridIdx][digit] !=0){
                        return false;
                    }
                    rowVec[i][digit] = 1;
                    colVec[j][digit] = 1;
                    gridVec[gridIdx][digit] = 1;
                }
            }
        }
        
        return true;
    }

int main (){

	//vector<vector<char>> board {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
	//bool res = exist(board, "AAB");
	vector<vector<int>> baord{{"5","3",".",".","7",".",".",".","."},{"6",".",".","1","9","5",".",".","."},{".","9","8",".",".",".",".","6","."},{"8",".",".",".","6",".",".",".","3"},{"4",".",".","8",".","3",".",".","1"},{"7",".",".",".","2",".",".",".","6"},{".","6",".",".",".",".","2","8","."},{".",".",".","4","1","9",".",".","5"},{".",".",".",".","8",".",".","7","9"}};
	
	isValidSudoku(board);


	return 0;
}

