#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <unordered_map>
#include <cstdint>
using namespace std;
    bool isSameTree(TreeNode* p, TreeNode* q) {
        
        if(!p && !q) return true;
        if((p && !q) || (!p && q)) return false;
        
        if(p->val != q->val) return false;
        
        
        if(p->left || q->left){  
            if(!isSameTree(p->left, q->left)) return false;
        }
        
        if(p->right || q->right){
            if(!isSameTree(p->right, q->right)) return false;
        }
        
        return true;
    }

int main (){

	//vector<vector<char>> board {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
	//bool res = exist(board, "AAB");

	cout << res  << endl;


	return 0;
}

