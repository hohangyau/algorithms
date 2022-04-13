#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <unordered_map>
#include <cstdint>
#include <math.h>
using namespace std;

    bool backtracking(int start,  int target, vector<int>& dp){
       
        if(dp[start] > target) return false;
        for(int i = start; dp[i] <= target; ++i ){
            if(dp[i] == target ) return true;
            
            if((target - dp[i] > 0) && backtracking(i+1, target - dp[i], dp)){
               return true;    
            } 
        }

        return false;
    }
    
    bool checkPowersOfThree(int n) {
        int i = 1;
        vector<int> dp;
        dp.push_back(1);
        while(i*3 < n){
			i = i*3;
            dp.push_back(i);
        }
        dp.push_back(i*3);
		bool res = backtracking(0, n, dp);

        return res;// 
    }

int main (){

	//vector<vector<char>> board {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
	//bool res = exist(board, "AAB");

	
	bool res = checkPowersOfThree(12);
	cout << "result: " << res << endl;
	return 0;
}

