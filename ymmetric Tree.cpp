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
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return helper(root->left, root->right);
    }
    bool helper(TreeNode* l, TreeNode* r){
        if(!l && !r) return true;
        if(!l || !r) return false;
        return l->val==r->val && helper(l->left,r->right) && helper(l->right,r->left);
    }
};

int main() {
    int n; cin >> n;
    vector<TreeNode*> nodes(n,nullptr);
    for(int i=0;i<n;i++){ int val; cin >> val; nodes[i]=new TreeNode(val);}
    for(int i=0;i<n;i++){ int l,r; cin >> l >> r; if(l!=-1) nodes[i]->left=nodes[l]; if(r!=-1) nodes[i]->right=nodes[r]; }
    Solution sol;
    cout << (sol.isSymmetric(nodes[0]) ? "true" : "false");
}
