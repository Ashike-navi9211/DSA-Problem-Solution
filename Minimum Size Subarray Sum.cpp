#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size(), left = 0, sum = 0, minLen = INT_MAX;
        for (int right = 0; right < n; right++) {
            sum += nums[right];
            while (sum >= target) {
                minLen = min(minLen, right - left + 1);
                sum -= nums[left++];
            }
        }
        return minLen == INT_MAX ? 0 : minLen;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2,3,1,2,4,3};
    int target = 7;
    cout << "Minimum Subarray Length: " << sol.minSubArrayLen(target, nums) << endl;
    return 0;
}
