#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val; TreeNode* left; TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    void dfs(TreeNode* node, string path, vector<string>& res) {
        if(!node) return;
        path += to_string(node->val);
        if(!node->left && !node->right) res.push_back(path);
        else {
            path += "->";
            dfs(node->left,path,res);
            dfs(node->right,path,res);
        }
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        dfs(root,"",res);
        return res;
    }
};

int main() {
    Solution sol;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);

    vector<string> paths = sol.binaryTreePaths(root);
    cout << "Binary Tree Paths: ";
    for(auto s: paths) cout << s << " | ";
    cout << endl;
    return 0;
}

