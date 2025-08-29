#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0, candidate = 0;
        for (int num : nums) {
            if (count == 0) candidate = num;
            count += (num == candidate) ? 1 : -1;
        }
        return candidate;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {3,2,3};
    cout << "Majority Element: " << sol.majorityElement(nums) << endl;
    return 0;
}
