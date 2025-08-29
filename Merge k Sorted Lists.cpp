#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> array;

        // Extract values from all linked lists
        for (ListNode* list : lists) {
            while (list) {
                array.push_back(list->val);
                list = list->next;
            }
        }

        // Sort the array
        sort(array.begin(), array.end());

        // Convert sorted array back into a linked list
        ListNode dummy(0);
        ListNode* current = &dummy;

        for (int val : array) {
            current->next = new ListNode(val);
            current = current->next;
        }

        return dummy.next; // Head of merged sorted linked list
    }
};

// Helper function to create linked list from vector
ListNode* createList(vector<int> values) {
    ListNode dummy;
    ListNode* tail = &dummy;
    for (int val : values) {
        tail->next = new ListNode(val);
        tail = tail->next;
    }
    return dummy.next;
}

// Helper function to print linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Example input: 3 sorted linked lists
    vector<int> v1 = {1, 4, 5};
    vector<int> v2 = {1, 3, 4};
    vector<int> v3 = {2, 6};

    ListNode* l1 = createList(v1);
    ListNode* l2 = createList(v2);
    ListNode* l3 = createList(v3);

    vector<ListNode*> lists = {l1, l2, l3};

    Solution sol;
    ListNode* mergedHead = sol.mergeKLists(lists);

    cout << "Merged Sorted List: ";
    printList(mergedHead);

    return 0;
}
