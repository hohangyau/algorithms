/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* dfs(TreeNode* root, unordered_set<int> toDelete, vector<TreeNode*> &remaining){
        
        if(!root) return NULL;
        
        root->left = dfs(root->left, toDelete, remaining);
        root->right = dfs(root->right, toDelete, remaining);
        
        if(toDelete.count(root->val) == 0){
            return root;
        }
        
        if(root->left) {
            remaining.push_back(root->left);
        }
        
        if(root->right) {
            remaining.push_back(root->right);
        }
        
        return NULL;
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> toDelete;
        vector<TreeNode*> remaining;
        for(int i = 0; i < to_delete.size(); ++i){
            toDelete.insert(to_delete[i]);
        }
        dfs(root, toDelete, remaining);
        if(toDelete.count(root->val) ==0 ){
            remaining.push_back(root);
        }
        return remaining;
    }
};