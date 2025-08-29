#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int longest = 0;

        for (int num : nums) {
            if (!s.count(num - 1)) {
                int currentNum = num;
                int streak = 1;

                while (s.count(currentNum + 1)) {
                    currentNum++;
                    streak++;
                }
                longest = max(longest, streak);
            }
        }
        return longest;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    cout << "Longest Consecutive Sequence: " << sol.longestConsecutive(nums) << endl;
    return 0;
}
