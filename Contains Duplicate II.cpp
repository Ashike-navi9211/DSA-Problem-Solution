#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        for (int i=0;i<nums.size();i++){
            if (m.count(nums[i]) && i - m[nums[i]] <= k) return true;
            m[nums[i]] = i;
        }
        return false;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1,2,3,1};
    int k = 3;
    cout << "Contains Nearby Duplicate: " << (sol.containsNearbyDuplicate(nums, k) ? "Yes" : "No") << endl;
    return 0;
}
