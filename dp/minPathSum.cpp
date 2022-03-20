#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <unordered_map>
#include <cstdint>
using namespace std;
int minPathSum(vector<vector<int>>& grid) {

		int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        
        
        dp[0][0] = grid[0][0];
        
        for(int i = 1; i < m; ++i ) {
            dp[i][0] = dp[i-1][0] + grid[i][0];
        }
        
         for(int i = 1; i < n; ++i ) {
            dp[0][i] = dp[0][i-1] + grid[0][i];
        }
        
        for(int i = 1; i < m; ++i){
            for(int j = 1; j < n; ++j){
                dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1]);
            }
        }
     
	 for(int i = 0; i < m; ++i) {
        for(int j = 0; j < n; ++j){
           cout <<  dp[i][j] ; 
		   cout << '\t';
			}cout << endl;
		}
        return dp[m-1][n-1];
}
int minPathSum2(vector<vector<int>>& grid) { //update grid in place
        int m = grid.size(), n = grid[0].size();
        
               
        for(int i = 1; i < m; ++i ) {
            grid[i][0] = grid[i-1][0] + grid[i][0];
        }
        
        for(int i = 1; i < n; ++i ) {
            grid[0][i] = grid[0][i-1] + grid[0][i];
        }
        
        for(int i = 1; i < m; ++i){
            for(int j = 1; j < n; ++j){
                grid[i][j] = grid[i][j] + min(grid[i-1][j], grid[i][j-1]);
            }
        }
        
        return grid[m-1][n-1];
    }
int main (){

	//vector<vector<char>> grid {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
		vector<vector<int>> grid{{1,3,1},{1,5,1},{4,2,1}};
		int res = minPathSum(grid);

	cout << res  << endl;


	return 0;
}

