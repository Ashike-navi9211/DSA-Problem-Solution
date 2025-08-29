#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* curr = head;
        while(curr && curr->next){
            if(curr->val == curr->next->val)
                curr->next = curr->next->next;
            else
                curr = curr->next;
        }
        return head;
    }
};

int main() {
    int n;
    cin >> n;
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    for(int i=0;i<n;i++){
        int val; cin >> val;
        ListNode* node = new ListNode(val);
        if(!head) head = tail = node;
        else { tail->next = node; tail = node; }
    }
    Solution sol;
    head = sol.deleteDuplicates(head);
    while(head){ cout << head->val << " "; head = head->next; }
}
