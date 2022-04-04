#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <unordered_map>
#include <cstdint>
using namespace std;

    bool hasCycle(ListNode *head) {
        if(!head || !head->next) return false;
        
        ListNode* fast = head->next->next;
        
        while(head && fast){
           
            if(head == fast){
                return true;
            }
            fast = fast->next ? fast->next->next : NULL;
            head = head->next;
        }
        return false;
        
    }
int main (){

	//vector<vector<char>> board {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
	//bool res = exist(board, "AAB");

	cout << res  << endl;


	return 0;
}

