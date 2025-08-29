#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        return s.size() != nums.size();
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1,2,3,1};
    cout << "Contains Duplicate: " << (sol.containsDuplicate(nums) ? "Yes" : "No") << endl;
    return 0;
}
