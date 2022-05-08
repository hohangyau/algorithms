#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <unordered_map>
#include <cstdint>
#include <stack>
using namespace std;
    bool isValid(string s) {
        stack<char> stackA;

        
        for(int i = 0; i < s.size(); ++i){
            char ch = s[i];
            
            if(ch == '\(' || ch == '\{' || ch == '\[' ){
                stackA.push(ch);
            }
   
            
            if(ch == '\)'){
                if(stackA.empty() || stackA.top() != '\('){
                    return false;
                }
                stackA.pop();
            }
            if(ch == '\}'){
                if(stackA.empty() || stackA.top() != '\{'){
                    return false;
                }
                stackA.pop();            
            }
            if(ch == '\]'){
                if(stackA.empty() || stackA.top() != '\['){
                    return false;
                }
                stackA.pop();            
            }            
            
        }
        
        return stackA.empty();
    }

int main (){

	//vector<vector<char>> board {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
	//bool res = exist(board, "AAB");
	string s = "()";
	char ch  = s[0];
	bool res = ch == '\(';
	cout << res << endl;


	return 0;
}

