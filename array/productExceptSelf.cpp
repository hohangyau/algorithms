#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <unordered_map>
#include <cstdint>
using namespace std;

   vector<int> productExceptSelf(vector<int>& nums) {

        int n = nums.size();
        vector<int> dp(n);
        dp[0] = nums[0];
        
        for(int i = 1; i < n; ++i){
            dp[i] = nums[i] * dp[i-1];
        }
        
        dp[n-1] = dp[n-2];
        int rightSoFar = nums[n-1];
        
        for(int i = n-2; i>0; --i){
            dp[i] = dp[i-1] * rightSoFar;
            rightSoFar *= nums[i];
        }
            
        dp[0] = rightSoFar;

        
        return dp;
    }
int main (){

	//vector<vector<char>> board {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
	//bool res = exist(board, "AAB");
	vector<int> vec {2,3,5,0};
	vec = productExceptSelf(vec);
	for(auto i : vec){
		cout << i << " " << endl;
	}


	return 0;
}

