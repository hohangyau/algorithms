#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <unordered_map>
#include <cstdint>
using namespace std;

void q_sort(vector<int>& nums, int l, int r, int k){
	cout << l <<"\t" << r << endl;
	if( l+1 >=r){
		return;
	}
	int first = l, last = r-1, key = nums[first];
	while(first < last){
		while(first < last && nums[last] >= key){
			--last;
		}
		nums[first] = nums[last];
		while(first < last && nums[first] <= key){ //0<2
			++first;
		}

		nums[last] = nums[first];
	}

	nums[first] = key;
		cout << "after while loop:" << "\t" << endl;
		cout << first << endl;
		cout << endl;
	for(int num : nums){
		cout << num << endl;
	}
	if(r-k > first){
		q_sort(nums, first+1, r,  k);
	}
	if(r-k < first) {
		q_sort(nums, l, first,  k);

	}
	
	
}
    int findKthLargest(vector<int>& nums, int k) {
        q_sort(nums, 0, nums.size(), k);
        return nums[nums.size()-k];
    }
int main (){

	//vector<vector<char>> board {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
	//bool res = exist(board, "AAB");
	vector<int> nums{7,6,5,4,3,2,1};
	//q_sort(nums, 0, 5);
	//vector<int> nums{3, 2, 1, 5, 6, 4};

	int res = findKthLargest(nums, 5);

	//cout << res << endl;

	return 0;
}

