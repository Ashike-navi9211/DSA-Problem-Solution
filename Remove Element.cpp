#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int j = 0; // index for valid elements
        for (int i = 0; i < n; i++) {
            if (nums[i] != val) {   // keep only non-val elements
                nums[j] = nums[i];
                j++;
            }
        }
        return j; // new length
    }
};

int main() {
    vector<int> nums = {3, 2, 2, 3, 4, 2, 5};
    int val = 2;

    Solution sol;
    int k = sol.removeElement(nums, val);

    cout << "New length after removing " << val << " = " << k << endl;
    cout << "Array after removal: ";
    for (int i = 0; i < k; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}
