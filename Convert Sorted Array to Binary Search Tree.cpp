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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums,0,nums.size()-1);
    }
    TreeNode* helper(vector<int>& nums,int l,int r){
        if(l>r) return nullptr;
        int mid = (l+r)/2;
        TreeNode* node = new TreeNode(nums[mid]);
        node->left=helper(nums,l,mid-1);
        node->right=helper(nums,mid+1,r);
        return node;
    }
};

int main() {
    int n; cin >> n;
    vector<int> nums(n);
    for(int i=0;i<n;i++) cin >> nums[i];
    Solution sol;
    TreeNode* root = sol.sortedArrayToBST(nums);
    cout << root->val; // root value as output check
}
