#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        inorder(root, result);
        return result;
    }
    void inorder(TreeNode* node, vector<int>& res){
        if(!node) return;
        inorder(node->left, res);
        res.push_back(node->val);
        inorder(node->right, res);
    }
};

int main() {
    int n;
    cin >> n;
    vector<TreeNode*> nodes(n, nullptr);
    for(int i=0;i<n;i++){
        int val; cin >> val;
        nodes[i] = new TreeNode(val);
    }
    for(int i=0;i<n;i++){
        int l,r; cin >> l >> r;
        if(l!=-1) nodes[i]->left = nodes[l];
        if(r!=-1) nodes[i]->right = nodes[r];
    }
    Solution sol;
    vector<int> ans = sol.inorderTraversal(nodes[0]);
    for(int val: ans) cout << val << " ";
}
