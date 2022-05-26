#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <unordered_map>
#include <cstdint>
using namespace std;
    vector<vector<int>> dp;
    void dfs(vector<int>& nums, int i, int j){
        if(i == j){
            dp.push_back({nums[i]});
            return;
        }
        
        dfs(nums, i+1, j);
       
        int n = dp.size();
        for(int k = 0; k < n; ++k){
            vector<int> temp = dp[k];
            temp.push_back(nums[i]);
            dp.push_back(temp);
        }
         dp.push_back({nums[i]});
        return;
        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(nums, 0, nums.size()-1);
        dp.push_back({});
        return dp;
    }

int main (){

	//vector<vector<char>> board {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
	//bool res = exist(board, "AAB");

	cout << res  << endl;


	return 0;
}

