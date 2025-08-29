#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *a = headA, *b = headB;
        while (a != b) {
            a = a ? a->next : headB;
            b = b ? b->next : headA;
        }
        return a;
    }
};

int main() {
    Solution sol;
    ListNode* a = new ListNode(4);
    a->next = new ListNode(1);
    ListNode* b = new ListNode(5);
    b->next = new ListNode(6);
    b->next->next = new ListNode(1);
    ListNode* c = new ListNode(8);
    c->next = new ListNode(4);
    c->next->next = new ListNode(5);
    a->next->next = c;
    b->next->next->next = c;

    ListNode* inter = sol.getIntersectionNode(a, b);
    cout << "Intersection Node: " << (inter ? inter->val : -1) << endl;
    return 0;
}
