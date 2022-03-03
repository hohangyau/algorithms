#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <unordered_map>
#include <cstdint>
using namespace std;



void upLeft( vector<vector<int>>& dp, int i, int j, int n, int m ) {
	
		if (j > 0) {
			dp[i][j] = min(dp[i][j], dp[i][j-1] + 1);
		}
		
		if (i > 0) {
			dp[i][j] = min(dp[i][j], dp[i-1][j] + 1);
		}	
	
}
void downRight( vector<vector<int>>& dp, int i, int j  ) {
	int n = dp.size();
	int m = dp[i].size();

	if (j < m - 1) {
		dp[i][j] = min(dp[i][j], dp[i][j+1] + 1);
		
	}
	if (i < n - 1) {
		dp[i][j] = min(dp[i][j], dp[i+1][j] + 1);
		
	}
}
vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
	


	int n = mat.size(), m = mat[0].size();
	vector<vector<int>> dp(n, vector<int>(m, INT_MAX - 1));
		
        for(int i = 0; i < n; ++i){
            for (int j = 0; j < m; ++j) {
				cout << mat[i][j] << " ";
				if(mat[i][j] == 0){ 
				dp[i][j] = 0;
				}
				else {
				upLeft(dp, i, j, n, m);
				};
				
            }cout << endl;
        }
		cout << "after bottom left" << endl;
		for(int i = 0; i < dp.size() ; ++i){
            for (int j = 0; j < dp[i].size(); ++j) {
				cout << dp[i][j] << " ";
            }cout << endl;
        }		
		
		for(int i = n - 1; i >= 0 ; --i){
            for (int j = m - 1; j >= 0; --j) {
				if(mat[i][j] != 0) {
					if (j < m - 1) {
					dp[i][j] = min(dp[i][j], dp[i][j+1] + 1);
					}
					if (i < n - 1) {
					dp[i][j] = min(dp[i][j], dp[i+1][j] + 1);
					}
				}
            }
        }

		cout << "after right up:" << endl;
		for(int i = 0; i < dp.size() ; ++i){
            for (int j = 0; j < dp[i].size(); ++j) {
				cout << dp[i][j] << " ";
            }cout << endl;
        }
		
		return dp;
}
int main (){
	
	//vector<vector<int>> mat{{1,1,1},{1,1,1},{1,0,1}};

	//vector<vector<int>> mat{{1,1,1},{1,1,1},{1,0,1}};
	vector<vector<int>> mat{{1,1,0,0,1,0,0,1,1,0},{1,0,0,1,0,1,1,1,1,1},{1,1,1,0,0,1,1,1,1,0},{0,1,1,1,0,1,1,1,1,1},{0,0,1,1,1,1,1,1,1,0},{1,1,1,1,1,1,0,1,1,1},{0,1,1,1,1,1,1,0,0,1},{1,1,1,1,1,0,0,1,1,1},{0,1,0,1,1,0,1,1,1,1},{1,1,1,0,1,0,1,1,1,1}};
	
	//vector<vector<int>> mat{{1,0,1,1,0,0,1,0,0,1},{0,1,1,0,1,0,1,0,1,1},{0,0,1,0,1,0,0,1,0,0},{1,0,1,0,1,1,1,1,1,1},{0,1,0,1,1,0,0,0,0,1},{0,0,1,0,1,1,1,0,1,0},{0,1,0,1,0,1,0,0,1,1},{1,0,0,0,1,1,1,1,0,1},{1,1,1,1,1,1,1,0,1,0},{1,1,1,1,0,1,0,0,1,1}};
	//bool res = exist(board, "AAB");
	updateMatrix(mat);
	//cout << res  << endl;
	
	//cout << min(min(2, 999), min(3, 999)) << endl;


	return 0;
}

