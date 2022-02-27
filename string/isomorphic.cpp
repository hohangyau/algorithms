#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <unordered_map>
#include <cstdint>
using namespace std;
bool isIsomorphic(string s, string t) { 
	vector<int> s_vec(256, -1);
	vector<int> t_vec(256, -1);

	s_vec[s[0]] = 0;
	s_vec[t[0]] = 0;
	for(int i = 1; i < s.size(); ++i){
		if( s_vec[s[i]] !=  t_vec[t[i]] )  {
			
			//return false;
		}
		s_vec[s[i]] = i;
		t_vec[t[i]] = i;
	}
	
	
	for(int i = 0; i < s.size(); ++i){

		cout << s_vec[s[i]]  << '\t' <<  t_vec[t[i]] << endl;

	}
	
	
	return true;
}

int main (){
	//vector<vector<char>> board {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
	//bool res = exist(board, "AAB");
	//cout << isIsomorphic("add", "egg") << endl;	
	//cout << isIsomorphic("foo", "bar") << endl;	
	//cout << isIsomorphic("paper", "title") << endl;	
	//cout << isIsomorphic("13", "42") << endl;	
	//cout << isIsomorphic("133", "421") << endl;	
	isIsomorphic("aa", "ab");
	//isIsomorphic("add", "egg");
	return 0;
}

