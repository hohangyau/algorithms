#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <unordered_map>
#include <cstdint>
using namespace std;
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i = 0; i < n - 1; ++i){
            if(nums[i+1] != nums[i] + 1) 
                return nums[i] + 1;
        }
        if(nums[n-1] == n) return 0;
        return nums[n-1] + 1;
    }

int main (){

	//vector<vector<char>> board {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
	//bool res = exist(board, "AAB");

	cout << res  << endl;


	return 0;
}

