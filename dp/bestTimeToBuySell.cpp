#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <unordered_map>
#include <cstdint>
using namespace std;
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0, curMin = prices[0];
        
        for(int i = 1; i < prices.size(); ++i){
            maxProfit = max(maxProfit, prices[i] - curMin);
            curMin = min(curMin, prices[i]);
            
        }
        
        return maxProfit;
    }

int main (){

	//vector<vector<char>> board {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
	//bool res = exist(board, "AAB");

	cout << res  << endl;


	return 0;
}

