#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <unordered_map>
#include <cstdint>
using namespace std;

    int longestPalindrome(string s) {
        unordered_map<char, int> dict;
		bool single = false;
		int count = 0;
        for(int i = 0; i < s.size(); ++i){
            ++dict[s[i]];
        }
		for(int i = 0; i < dict.size(); ++i){
			if( dict[i] > 0 ){	
				count += dict[i] % 2 == 0 ? dict[i] :  dict[i] - 1;
			}
			if(single == false && (dict[i] == 1 || dict[i] % 2  != 0)) {
				single = true;
                ++count;
			}
		}
		return count;
}

int main (){

	//vector<vector<char>> board {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
	//bool res = exist(board, "AAB");
	string res = "bb";
	cout <<  longestPalindrome(res) << endl;


	return 0;
}

