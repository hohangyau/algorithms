#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <unordered_map>
#include <cstdint>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
      ListNode* helper(ListNode* a, ListNode* b){
        ListNode* temp = b->next;
		b->next = a;
        a->next = temp;
       
        return b;
    }
	
    ListNode* swapPairs(ListNode* head) {
		
		ListNode * s;
		
		if(head && head->next){
			s = head->next->next;
			head = helper(head, head->next);
        }
		
        while(true){
            if(!s || !s->next) break;

        }
		return head;
    }
    ListNode* swapPairsRecursive(ListNode* head) {
		if(!head || !head->next){
			return head;
		}
		
        ListNode* temp = head->next;
		head->next = swapPairsRecursive(head->next->next);
        temp->next = head;
		
		return temp;
    }	
int main (){


	//ListNode* b = new ListNode(2, NULL);
	ListNode* a = new ListNode(1, 
					new ListNode(2, 
						new ListNode(3, 
							new ListNode(4, NULL))));
	
	ListNode* temp = a;
	while(temp){
		//cout << temp->val << endl;
		temp = temp->next;
	}
	
	//;
	ListNode* temp2 = swapPairsRecursive(a);
	
	while(temp2){
		cout << temp2->val << endl;
		temp2 = temp2->next;
	}
	return 0;
}

