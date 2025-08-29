#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q) return true;
        if(!p || !q) return false;
        return p->val == q->val && isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
    }
};

int main() {
    int n1,n2;
    cin >> n1 >> n2;
    vector<TreeNode*> tree1(n1,nullptr), tree2(n2,nullptr);
    for(int i=0;i<n1;i++){ int val; cin >> val; tree1[i]=new TreeNode(val);}
    for(int i=0;i<n2;i++){ int val; cin >> val; tree2[i]=new TreeNode(val);}
    for(int i=0;i<n1;i++){ int l,r; cin >> l >> r; if(l!=-1) tree1[i]->left=tree1[l]; if(r!=-1) tree1[i]->right=tree1[r]; }
    for(int i=0;i<n2;i++){ int l,r; cin >> l >> r; if(l!=-1) tree2[i]->left=tree2[l]; if(r!=-1) tree2[i]->right=tree2[r]; }
    Solution sol;
    cout << (sol.isSameTree(tree1[0], tree2[0]) ? "true" : "false");
}
