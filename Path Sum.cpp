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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;
        if(!root->left && !root->right) return root->val==targetSum;
        return hasPathSum(root->left,targetSum-root->val) || hasPathSum(root->right,targetSum-root->val);
    }
};

int main() {
    int n,target; cin >> n >> target;
    vector<TreeNode*> nodes(n,nullptr);
    for(int i=0;i<n;i++){ int val; cin >> val; nodes[i]=new TreeNode(val);}
    for(int i=0;i<n;i++){ int l,r; cin >> l >> r; if(l!=-1) nodes[i]->left=nodes[l]; if(r!=-1) nodes[i]->right=nodes[r]; }
    Solution sol;
    cout << (sol.hasPathSum(nodes[0],target) ? "true" : "false");
}
