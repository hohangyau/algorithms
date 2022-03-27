#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <unordered_map>
#include <cstdint>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int curMax = 0, l = 0, r = height.size()-1; 
        
        
        while(l != r) {
            
            if(height[l] > height[r]){
                curMax = max(curMax, height[r] * (r - l));
                --r;
            }else {
                curMax = max(curMax, height[l] * (r - l));
                ++l;
            }
            
        }
        
        return curMax;
    }
};
int main (){

	//vector<vector<char>> board {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
	//bool res = exist(board, "AAB");

	cout << res  << endl;


	return 0;
}

