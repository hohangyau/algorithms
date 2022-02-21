#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <unordered_map>
#include <cstdint>
using namespace std;

bool isAnagram(string s, string t) {

		
	if(s.size() != t.size()){
		return false;
	}
        unordered_map<char, int> myMap;
        for(int i = 0; i < s.size(); ++i) {
			myMap[s[i]] += 1;
			myMap[t[i]] -= 1;
		}
		
		for(int i = 0; i < s.size(); ++i) {
			if(myMap[s[i]] != 0) return false;
		}

	return true;
			
} 

int main (){

	//vector<vector<char>> board {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
	//bool res = exist(board, "AAB");
	//bool res = isAnagram("anagram", "nagaram");
	bool res1 = isAnagram("res", "rat");

	//cout << res << endl;
	//cout << res1 << endl;



	return 0;
}

