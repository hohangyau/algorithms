/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestorRecursive(TreeNode* root, int first, int second) {
        if (first < root->val && second < root->val ){
            return lowestCommonAncestorRecursive(root->left, first, second);
        }
        if(first > root->val && second > root->val ){
            return lowestCommonAncestorRecursive(root->right, first, second);
        }

        return root;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return lowestCommonAncestorRecursive(root, p->val, q->val);
    }
};