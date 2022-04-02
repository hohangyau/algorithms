#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <unordered_map>
#include <cstdint>
using namespace std;
    int binarySearchRecursive(vector<int>& nums, int low, int hi){
        
        if (low == hi) return nums[low];
        
        //int m = (hi - low) % 2 == 0 ? (hi - low) / 2 : (hi - low) / 2 + 1;
         int m = low + ((hi - low) / 2);
         if ( (nums[low] < nums[m] && nums[low] < nums[hi]) ||
              (nums[m-1] < nums[m] && nums[m-1] < nums[hi])) return binarySearchRecursive(nums, low, m-1);
        
         return binarySearchRecursive(nums, m, hi);
        
    }
    int findMin2(vector<int>& nums) {
        
        int n = nums.size();
        if(n == 1) return nums[0];
        
        return binarySearchRecursive(nums, 0, n-1);
        
    }
int findMin(vector<int>& nums) {
        
        int low = 0, hi = nums.size()-1;
        while(low < hi){
        
            if(nums[low] < nums[hi]) return nums[low];
            
            int m = (hi + low) / 2 ;
            
            if( nums[m] >= nums[low]) {
                low = m+1;
            }
            else {
                hi = m;
            }
        }
        
        return nums[low];
    }
int main (){

	//vector<vector<char>> board {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
	vector<int> nums = {4,5,6,7,0,1,2};
	//bool res = exist(board, "AAB");
	int res = findMin2(nums);	
	cout << res  << endl;


	return 0;
}

