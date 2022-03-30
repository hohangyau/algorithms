#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <unordered_map>
#include <cstdint>
using namespace std;
    int lengthOfLongestSubstring(string s) {
        int l = 0, r = 0, curMax = 0, result = 0;
        unordered_set<char> mySet;
        
        
        while(r < s.size()) {
            char ch = s[r];
            if(mySet.count(ch) == 0) {
                mySet.insert(ch);
                curMax += 1;
                result = max(curMax, result);
                ++r;
            }else{
                while(mySet.count(ch) != 0){
                    mySet.erase(s[l]);
                    ++l;
                }
                curMax = r - l + 1;
                mySet.insert(ch);
                ++r;
            }
        }
        
        return result;
    }

int main (){

	//vector<vector<char>> board {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
	//bool res = exist(board, "AAB");

	cout << res  << endl;


	return 0;
}

