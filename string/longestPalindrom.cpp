#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <unordered_map>
#include <cstdint>
using namespace std;

    pair<int, int> twoPointers(string s, int l, int r, pair<int, int> curMax) {
        int count;
        while(l >= 0 && r < s.size() && s[l] == s[r]){
			//cout << endl;
			//cout << l << '\t' << r << endl;
			if(curMax.second <= (r-l)) {
				curMax = make_pair(l,r-l+1);
			}
            //++count;
            --l;
            ++r;

        }
        
        return curMax;
        
    }
string longestPalindrome(string s) {
    pair<int, int> res = make_pair(0, 1);
    
    for(int i = 0; i < s.size(); ++i) {
		//cout << "i" << '\t' << i << endl; 
        res = twoPointers(s, i, i, res);
        res = twoPointers(s, i, i+1, res);
    }
	cout << res.first << endl;
	cout << res.second << endl;
	
   // return s;
    return s.substr(res.first, res.second);
}
int main (){

	//vector<vector<char>> board {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
	//bool res = exist(board, "AAB");
	string s = "babad";
	cout << longestPalindrome(s)  << endl;


	return 0;
}

