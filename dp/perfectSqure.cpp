#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <unordered_map>
#include <cstdint>
#include <math.h>  
using namespace std;

int numSquares(int n) {
		
        vector<int> dp(n+1, INT_MAX);
		vector<int> nums;
        nums.push_back(0);
		dp[0] = 0;
        int count = 1, i = 1;
        while (count <= n) {
		  count = i * i;
          nums.push_back(count);
          ++i;  
        }
		
	for(int i = 1; i <=n; ++i){
		for(int j = 1; nums[j] <= i; ++j){

			dp[i] = min(dp[i], dp[i-nums[j]] + 1);


		}
	}
				
		return dp[n];
}

int main (){

	//vector<vector<char>> board {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
	int res = numSquares(4);
	//int res1 = numSquares(13);
	cout <<"result " << res  << endl;
	//cout <<"result1 " << res1  << endl;

	//cout << sqrt(12) << endl;
	return 0;
}

