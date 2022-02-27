#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <unordered_set>
#include <cstdint>
using namespace std;
bool twoPointers(string s){
        int first = 0;
        int last = s.size() - 1;
        while( first < last){
            if( s[first] != s[last]) return false;
            ++first;
            --last;
        }
        return true;
}
int countSubstrings(string s) {
        unordered_set<string> dict; 
		int count = 0;
		int left = 0;
		while(left < s.size() ){
			int right = 1;
			while(right <= s.size() - left){
				string str = s.substr(left, right);
				if(dict.count(str) || twoPointers(str) ) {
					dict.insert(str);
					count += 1;
				}
				right +=1;
			}
			left +=1;
		}
        
        return count;
        
}
void stringFun(string s){

	cout << s.substr(0, 1) << endl;
	cout << s.substr(0, 2) << endl;
	cout << s.substr(0, 3) << endl;
	cout << s.substr(1, 1) << endl;

	cout << s.substr(1, 2) << endl;
	cout << s.substr(1, 3) << endl;	
}
int main (){

	//vector<vector<char>> board {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
	//bool res = exist(board, "AAB");
	string s = "aaaaa";
	cout << countSubstrings(s);
return 0;	
}

