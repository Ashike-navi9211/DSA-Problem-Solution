#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* newnode = head->next; 
        ListNode* ptr1 = head;
        ListNode* ptr2 = head->next;
        ListNode* prev = nullptr;

        while (ptr1 != nullptr && ptr2 != nullptr) {
            // Swap
            ptr1->next = ptr2->next;
            ptr2->next = ptr1;

            // Connect previous part
            if (prev != nullptr) {
                prev->next = ptr2;
            }

            // Move forward
            prev = ptr1;
            ptr1 = ptr1->next;
            if (ptr1 != nullptr) {
                ptr2 = ptr1->next;
            } else {
                ptr2 = nullptr;
            }
        }

        return newnode;
    }
};

// Helper to create linked list from vector
ListNode* createList(vector<int> values) {
    ListNode dummy(0);
    ListNode* tail = &dummy;
    for (int val : values) {
        tail->next = new ListNode(val);
        tail = tail->next;
    }
    return dummy.next;
}

// Helper to print linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    vector<int> vals = {1, 2, 3, 4, 5};
    ListNode* head = createList(vals);

    cout << "Original List: ";
    printList(head);

    Solution sol;
    ListNode* swapped = sol.swapPairs(head);

    cout << "After Swapping Pairs: ";
    printList(swapped);

    return 0;
}
