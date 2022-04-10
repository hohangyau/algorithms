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

    vector<vector<int>> dp;    
    int findHeight(TreeNode* root){
        if(!root ) return 0;
        
        if (!root->right && !root->left) return 1;
        
        if(!root->left) return findHeight(root->right)  + 1;
        if(!root->right) return findHeight(root->left)  + 1;
        
        return max(findHeight(root->right), findHeight(root->left)) + 1;
        
    }
    
    void dfs(TreeNode* root, int level){
        if(!root) return;

        dp[level].push_back(root->val);
        
        if(!root->left && !root->right) return;
        
        if(root->left){
            dfs(root->left, level+1);
           // return ;
        }
        
        if(root->right) {
            dfs(root->right, level+1);
           // return;
        }
    
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};
        int h = findHeight(root);
        cout << h;
        for(int i = 0; i < h; ++i){
            dp.push_back({});
        }
        dfs(root, 0);
        return dp;
    }
int main (){

	//vector<vector<char>> board {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
	//bool res = exist(board, "AAB");

	TreeNode* root = new TreeNode(9);
	levelOrder(root);
	cout << dp.size() << endl;

	return 0;
}

