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
    bool isBalanced(TreeNode* root) {
        return height(root)!=-1;
    }
    int height(TreeNode* node){
        if(!node) return 0;
        int l = height(node->left);
        if(l==-1) return -1;
        int r = height(node->right);
        if(r==-1) return -1;
        if(abs(l-r)>1) return -1;
        return 1 + max(l,r);
    }
};

int main() {
    int n; cin >> n;
    vector<TreeNode*> nodes(n,nullptr);
    for(int i=0;i<n;i++){ int val; cin >> val; nodes[i]=new TreeNode(val);}
    for(int i=0;i<n;i++){ int l,r; cin >> l >> r; if(l!=-1) nodes[i]->left=nodes[l]; if(r!=-1) nodes[i]->right=nodes[r]; }
    Solution sol;
    cout << (sol.isBalanced(nodes[0]) ? "true" : "false");
}
