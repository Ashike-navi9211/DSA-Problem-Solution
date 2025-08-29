#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        ListNode dummy;
        
        ListNode* tail = &dummy;
        
        while (list1 != nullptr && list2 != nullptr) {
            
            if (list1->val < list2->val) {
                
                tail->next = list1;
                
                list1 = list1->next;
                
            } else {
                
                tail->next = list2;
                
                list2 = list2->next;
            }
            
            tail = tail->next;
        }
        
        tail->next = list1 ? list1 : list2;
        
        return dummy.next;
    }
};

void printList(ListNode* head) {
    
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    
    ListNode* list1 = new ListNode(1, new ListNode(2, new ListNode(4)));
    
    ListNode* list2 = new ListNode(1, new ListNode(3, new ListNode(4)));
    
    Solution sol;
    
    ListNode* merged = sol.mergeTwoLists(list1, list2);
    
    printList(merged);
    
    return 0;
}
