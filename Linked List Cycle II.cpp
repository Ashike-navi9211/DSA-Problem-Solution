
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                ListNode* start = head;
                while (start != slow) {
                    start = start->next;
                    slow = slow->next;
                }
                return start;
            }
        }
        return nullptr;
    }
};

int main() {
    Solution sol;
    ListNode* head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);
    head->next->next->next->next = head->next; // cycle
    ListNode* cycleNode = sol.detectCycle(head);
    if (cycleNode) cout << "Cycle starts at node: " << cycleNode->val << endl;
    else cout << "No cycle" << endl;
    return 0;
}
