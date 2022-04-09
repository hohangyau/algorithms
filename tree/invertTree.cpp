#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <unordered_map>
#include <cstdint>
using namespace std;
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
	 
};
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return root;
        if(!root->left && !root->right) return root;
        
        if(!root->left){
            root->left = invertTree(root->right);
            root->right = NULL;
            return root;
        }
        
        if(!root->right){
            root->right = invertTree(root->left);
            root->left = NULL;
            return root;
        }
        
        TreeNode* temp = root->left;
        root->left = invertTree(root->right); 
        root->right = invertTree(temp);
        
        return root;
    }
int main (){

	//vector<vector<char>> board {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
	//bool res = exist(board, "AAB");

	cout << res  << endl;


	return 0;
}

