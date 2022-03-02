#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <unordered_map>
#include <cstdint>
using namespace std;

bool helper(vector<int>& dp, int current, int k){
	//cout << "size" << " " << dp.size() << endl;
	for(int i = 0; i < dp.size(); ++i) {
		if(( dp[i] + current ) == k ) return true;
		dp[i]  = (dp[i] + current) % k; 
	}
	return false;
}

bool checkSubarraySum(vector<int>& nums, int k) {
	vector<int> dp;
	for(int i = 0; i < nums.size(); ++i){
		if (helper(dp, nums[i], k)) return true;
		if (nums[i] == 0) dp.push_back(k);
		else {
			dp.push_back(nums[i] % k);
	
		}
	}
	return false;
}

int main (){

	//vector<vector<char>> board {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
	//bool res = exist(board, "AAB");
	//vector<int>nums{23, 2, 6, 4, 7};
	vector<int>nums{5, 0, 0, 0, 0};
	bool res = checkSubarraySum(nums, 3);
	cout << res << endl;
	while (false) {
		
	
	int i; 
	cin >> i;
	
	cout << i % 3 << endl;
	cout << endl;
	//cout << res  << endl;

	}
	
	return 0;
}

