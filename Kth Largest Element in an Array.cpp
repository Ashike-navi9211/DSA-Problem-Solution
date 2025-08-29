#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq(nums.begin(), nums.end());
        for (int i = 1; i < k; i++) pq.pop();
        return pq.top();
    }
};

int main() {
    Solution sol;
    vector<int> nums = {3,2,1,5,6,4};
    int k = 2;
    cout << "Kth Largest Element: " << sol.findKthLargest(nums, k) << endl;
    return 0;
}
