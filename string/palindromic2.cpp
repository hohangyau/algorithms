#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <unordered_set>
#include <cstdint>
using namespace std;
int twoPointers(string s, int l, int r, int count){
		
        while( l >= 0 && r < s.size()  && s[l] == s[r] ){
			
            count += 1;
            r     += 1;
            l     -= 1;
        }
        return count;
}
int countSubstrings(string s) {
	
		int count = 0;
		for(int i = 0; i < s.size(); ++i){
			count = twoPointers(s, i, i, count);
		}
		
 		for(int i = 0; i < s.size() - 1; ++i){
			if(s[i] == s[i+1]){
				count = twoPointers(s, i, i+1, count);
			}
			
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

