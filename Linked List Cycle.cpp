#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(nullptr) {}
};

class Solution {
public:
    bool hasCycle(ListNode* head) {
        ListNode *slow=head, *fast=head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast) return true;
        }
        return false;
    }
};

int main() {
    int n,pos; cin >> n >> pos;
    vector<ListNode*> nodes(n,nullptr);
    for(int i=0;i<n;i++){ int val; cin >> val; nodes[i]=new ListNode(val);}
    for(int i=0;i<n-1;i++) nodes[i]->next=nodes[i+1];
    if(pos!=-1) nodes[n-1]->next=nodes[pos];
    Solution sol;
    cout << (sol.hasCycle(nodes[0]) ? "true" : "false");
}
