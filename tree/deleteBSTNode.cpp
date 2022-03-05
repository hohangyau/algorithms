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
 
 TreeNode* findMin(TreeNode* root) {
        if(root == NULL || root->left == NULL) return root;
        
        return findMin(root->left);
 
}
TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return root;
        
        if( key > root->val) {
            root->right = deleteNode(root->right, key);
            return root;
        }else if( key < root->val) {
            root->left = deleteNode(root->left, key);
            return root;
        }else { // root->val == key
            if(root->left == NULL && root->right == NULL) {
                TreeNode* temp = root;
                root = NULL;
                return root;
            }else if(root->left == NULL){
                TreeNode* temp = root;
                root = root->right;
                return root;
            }else if(root->right == NULL) {
               TreeNode* temp = root;
               root = root->left;
                return root;
            }else {
               TreeNode* temp = findMin(root->right);
               root->val = temp->val;
               root->right = deleteNode(root->right,temp->val);
               return root;
            }

        } 
        
        
    }
};

int main (){

	//vector<vector<char>> board {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
	//bool res = exist(board, "AAB");

	cout << res  << endl;


	return 0;
}

