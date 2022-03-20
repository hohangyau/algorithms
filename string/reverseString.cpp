#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <unordered_map>
#include <cstdint>
using namespace std;

string reverseStr(string s){
	string str;
	for(int i = s.size()-1; i >= 0; --i){
	cout << s[i] << endl;
	str += s[i];
	
	}
	return str;
}
int main (){

	//vector<vector<char>> board {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
	//bool res = exist(board, "AAB");
	
	string s = reverseStr("abcde");
	cout << s << endl;

	return 0;
}

