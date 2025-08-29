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
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        if(!root->left) return 1 + minDepth(root->right);
        if(!root->right) return 1 + minDepth(root->left);
        return 1 + min(minDepth(root->left), minDepth(root->right));
    }
};

int main() {
    int n; cin >> n;
    vector<TreeNode*> nodes(n,nullptr);
    for(int i=0;i<n;i++){ int val; cin >> val; nodes[i]=new TreeNode(val);}
    for(int i=0;i<n;i++){ int l,r; cin >> l >> r; if(l!=-1) nodes[i]->left=nodes[l]; if(r!=-1) nodes[i]->right=nodes[r]; }
    Solution sol;
    cout << sol.minDepth(nodes[0]);
}
