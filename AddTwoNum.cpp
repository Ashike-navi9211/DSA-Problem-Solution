#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* cur = dummy;
        int carry = 0;

        while(l1 || l2 || carry){
            int sum = carry;
            if(l1){ sum += l1->val; l1 = l1->next; }
            if(l2){ sum += l2->val; l2 = l2->next; }
            carry = sum / 10;
            cur->next = new ListNode(sum % 10);
            cur = cur->next;
        }
        return dummy->next;
    }
};

ListNode* makeList(vector<int> v){
    ListNode* head = new ListNode(0);
    ListNode* cur = head;
    for(int x : v){
        cur->next = new ListNode(x);
        cur = cur->next;
    }
    return head->next;
}

void printList(ListNode* head){
    while(head){
        cout << head->val;
        if(head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main(){
    Solution s;
    vector<int> v1 = {2,4,3};
    vector<int> v2 = {5,6,4};

    ListNode* l1 = makeList(v1);
    ListNode* l2 = makeList(v2);

    cout << "List1: "; printList(l1);
    cout << "List2: "; printList(l2);

    ListNode* ans = s.addTwoNumbers(l1,l2);

    cout << "Sum: "; printList(ans);
    return 0;
}
