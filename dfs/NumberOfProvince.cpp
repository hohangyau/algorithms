#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <unordered_map>
#include <cstdint>
using namespace std;

    int findCircleNum(vector<vector<int>>& isConnected) {
        int result = 0;
        vector<bool> dp(isConnected.size(), false);
        for(int i = 0; i < isConnected.size(); ++i ){
            if(!dp[i]){
                result += 1;
                dfs(isConnected, i ,dp);
            }
        }
        
        return result;
        
    }
    void dfs(vector<vector<int>>& grid, int k, vector<bool>& dp) {
        cout << k << endl;
        dp[k] = true;
        for(int i = 0; i < grid.size(); ++i) {
            if(grid[k][i] == 1 && dp[i] == false){
                dp[i] = true;
                dfs(grid, i, dp);
            }
        }
    }
int main (){

	//vector<vector<char>> board {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
	//bool res = exist(board, "AAB");

	cout << res  << endl;


	return 0;
}

