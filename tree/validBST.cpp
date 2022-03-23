#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <unordered_map>
#include <cstdint>
using namespace std;
    bool isValidBSTRecursive(TreeNode* root, long curMin, long curMax){
        
        
        if(!root){
            return true;
        };
        
        if(root->val <= curMin || root->val >= curMax) return false;
        if(root->left ){
             bool left = isValidBSTRecursive(root->left, curMin, root->val);
             if(!left ) return false;
            
        }
        
        if(root->right ){
            bool right = isValidBSTRecursive(root->right, root->val, curMax );
            if(!right ) return false;
            
        }
        
    
        return true;
        
    }
    bool isValidBST(TreeNode* root) {
        
        
        if(root){
            return isValidBSTRecursive(root, -2147483649, 2147483648);
            
        }
        
        //for (int i = 0; i <dp.size(); ++i){
         //   cout << dp[i].first << " " << dp[i].second << endl;
       // }
        
        return false;
    }

int main (){

	//vector<vector<char>> board {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
	//bool res = exist(board, "AAB");

	cout << res  << endl;


	return 0;
}

