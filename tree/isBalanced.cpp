#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <unordered_map>
#include <cstdint>
#include <math.h>
using namespace std;
    int helper(TreeNode* root) {
        if(root == NULL) return 0;
        
        int left = helper(root->left), right = helper(root->right);
        
        if(left == -1 || right == -1 || abs(left - right) > 1) return -1;
       return 1 + max(left,  right);
        
    }
    bool isBalanced(TreeNode* root) {
        return helper(root) != -1 ;

    }
int main (){

	//vector<vector<char>> board {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
	//bool res = exist(board, "AAB");

	cout << abs(0)  << endl;


	return 0;
}

