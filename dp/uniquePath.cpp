#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <unordered_map>
#include <cstdint>
using namespace std;
int dfs(vector<vector<int>>& grid, int i, int j) {
		cout << i << " " << j << endl;
		cout << endl;
        if(i == grid.size() - 1 && j == grid[i].size() -1 ) {
			cout << i << " " << j << endl;
            return 1;
        }
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[i].size() || grid[i][j] == 1) return 0;
        
		grid[i][j] = 1;
		int count = dfs(grid, i, j + 1) + dfs(grid, i + 1, j);
		grid[i][j] = 0;
		return count;

}
int dp(vector<vector<int>>& grid , int i, int j) {
	if(i == 0 && j == 0) return 1;
    if(i < 0 || j < 0 ) return 0;

    int left = j == 0 ? 0 : ( grid[i][j-1] > 0 ? grid[i][j-1] : dp(grid, i, j - 1));
	
    int up   = i == 0 ? 0 : (grid[i-1][j] > 0 ? grid[i-1][j] : dp(grid, i-1, j));

    grid[i][j] = left + up;


    return grid[i][j];
}


int uniquePaths3(int m, int n) {
	if( m == 1 && n == 1) return 1;
    vector<vector<int>> grid(m, vector<int>(n, 0));
    
    for(int i = 0; i < m ; ++i) {
        grid[i][0] = 1;
    }
    
    for(int i = 0; i < n ; ++i) {
         grid[0][i] = 1;
    }
    

    for(int i = 1; i < m; ++i) {
        for(int j = 1; j < n; ++j){
            grid[i][j] = grid[i][j-1] + grid[i-1][j];
        }
    }
    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < n; ++j){
         //  cout <<  grid[i][j] ; 
		  // cout << '\t';
        } //cout << endl;
    }
	
	return grid[m-1][n-1];
}

int uniquePaths(int m, int n) {
	if( m == 1 && n == 1) return 1;
    vector<vector<int>> grid(m, vector<int>(n, -1));
	grid[0][0] = 1;

	return dp(grid, m - 1, n - 1);
} 



int main (){

	//vector<vector<char>> board {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};

	int res = uniquePaths3(3, 2);
	int res2 = uniquePaths3(3, 7);
	int res3 = uniquePaths3(1, 2);
	cout << res  << endl;
	cout << res2  << endl;
	cout << res3  << endl;

	return 0;
}

