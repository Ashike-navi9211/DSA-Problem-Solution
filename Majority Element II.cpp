#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n1 = 0, n2 = 0, c1 = 0, c2 = 0;
        for (int num : nums) {
            if (num == n1) c1++;
            else if (num == n2) c2++;
            else if (c1 == 0) { n1 = num; c1 = 1; }
            else if (c2 == 0) { n2 = num; c2 = 1; }
            else { c1--; c2--; }
        }
        c1 = c2 = 0;
        for (int num : nums) {
            if (num == n1) c1++;
            else if (num == n2) c2++;
        }
        vector<int> res;
        if (c1 > nums.size()/3) res.push_back(n1);
        if (c2 > nums.size()/3) res.push_back(n2);
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {3,2,3};
    vector<int> res = sol.majorityElement(nums);
    cout << "Majority Elements (> n/3): ";
    for(int x: res) cout << x << " ";
    cout << endl;
    return 0;
}
