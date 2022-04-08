#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <unordered_map>
#include <cstdint>
using namespace std;
		/*	if(dp[i][j] == 1){
					if(heights[i][j] >= heights[i+1][j] || heights[i][j] >= heights[i][j+1]){

					}
				}
				if(heights[i][j] >= heights[i+1][j] || heights[i][j] >= heights[i][j+1]){
					if(dp[i][j] == 1 && (dp[i+1][j] == 1 && heights[i][j] >= heights[i+1][j] 
										||dp[i][j+1] == 1 && heights[i][j] >= heights[i][j+1] )){

					}else{
						dp[i][j] = 1;		
					}
				}else{
					dp[i][j] = 0;
			
				}	
				
		*/
		
	bool dfs(vector<vector<int>>& mat, int i, int j, vector<vector<int>>& dp){
		
		if( i == 0 || j == 0 
			|| mat[i][j] >= mat[i-1][j] && dp[i-1][j] == 1 
			|| mat[i][j] >= mat[i][j-1] && dp[i][j-1] == 1
			|| mat[i][j] >= mat[i+1][j] && dp[i+1][j] == 1 
			|| mat[i][j] >= mat[i][j+1] && dp[i][j+1] == 1 ){
			dp[i][j] = 1;
			return true;
		}
		
		if(i >= mat.size() || j >= mat[i].size()) return false;
		
		
		if(dfs(mat, i-1, j, dp) || dfs(mat, i+1, j, dp) ||　dfs(mat, i, j -1 , dp) || dfs(mat, i, j + 1 , dp)){
			dp[i][j]  = 1;
			return true;
		}
		
		dp[i][j] = 0;
		return false;
		
	}	
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> res;
		
		int m = heights.size(), n = heights[0].size();
		
        vector<vector<int>> dp(m, vector<int>(n, 0));
        vector<vector<int>> dp2(m, vector<int>(n, 0));
        for(int i = 0; i < m; ++i){
            dp[0][i] = 1;
        }
        
        for(int i = 0; i < m; ++i){
            dp[i][0] = 1;
        }
                
        for(int i = 1; i < m; ++i){
            for(int j = 1; j < n; ++j){
                if( (heights[i][j] >= heights[i-1][j] && dp[i-1][j] == 1) || (heights[i][j] >= heights[i][j-1] && dp[i][j-1] == 1)){
                    dp[i][j] = 1;
                }
            }
        }
		
		
		for(int j = 0; j < m; ++j){
			dp2[m-1][j] = 1;
        }
		
		for(int i = 0; i < m; ++i){
			dp2[i][n-1] = 1;
        }		
		
		for(int i = m - 2; i >= 0; --i){
			for(int j = n - 2; j >= 0; --j){
                if( (heights[i][j] >= heights[i+1][j] && dp2[i+1][j] == 1) || ( heights[i][j] >= heights[i][j+1] && dp2[i][j+1] == 1)){
                    dp2[i][j] = 1;
                }				
			}
		}
		cout << res.size() << endl;; 
		for(int i = 0; i < dp.size(); ++i) {
			for(int j = 0; j < dp[i].size(); ++j){
				cout << dp[i][j] << "  ";
			}cout << endl;
		}
				cout << res.size() << endl;; 

		for(int i = 0; i < dp2.size(); ++i) {
			for(int j = 0; j < dp2[i].size(); ++j){
				cout << dp2[i][j] << "  ";
			}cout << endl;
		}
		
		for(int i = 0; i < dp2.size(); ++i) {
			for(int j = 0; j < dp2[i].size(); ++j){
				if(dp[i][j] == 1 && dp2[i][j] == 1 ){
					vector<int> temp = {i, j};
					res.push_back(temp);					
				}
			}
		}		
						cout << res.size() << endl;; 

		return res;

    }
int main (){

	//vector<vector<char>> board {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
	//bool res = exist(board, "AAB");
	//vector<vector<int>> board{{1,2,2,3,5}, {3,2,3,4,4}, {2,4,5,3,1},{6,7,1,4,5},{5,1,1,2,4}};
	vector<vector<int>> board{{1,2,3}, {8,9,4}, {7,6,5}};
	pacificAtlantic(board);


	return 0;
}

