#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <unordered_map>
#include <cstdint>
using namespace std;
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        res[0] = 1;
        
        for(int i = 1; i < n; ++i) {
            res[i] = nums[i-1] * res[i-1];
        }
        
        int rightSoFar = nums[n-1];
        for(int i = n-2; i >= 0; --i){
            res[i] *= rightSoFar;
            rightSoFar *= nums[i];
        }
   
  
        
        return res;
    }

int main (){

	//vector<vector<char>> board {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
	//bool res = exist(board, "AAB");

	cout << res  << endl;


	return 0;
}

