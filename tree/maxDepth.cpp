#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <unordered_map>
#include <cstdint>
using namespace std;

    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
        
        if(root->left == NULL && root->right == NULL) return 1;
        
        else if(root->left == NULL) return maxDepth(root->right) + 1;
        else if(root->right == NULL) return maxDepth(root->left) + 1;
        else {
            return max( maxDepth(root->right),  maxDepth(root->left)) +1 ;
        }
    }
int main (){

	//vector<vector<char>> board {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
	//bool res = exist(board, "AAB");

	cout << res  << endl;


	return 0;
}

