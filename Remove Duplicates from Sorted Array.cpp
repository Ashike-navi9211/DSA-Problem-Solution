#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& num) {
        int n = num.size();
        if (n == 0) return 0;  // edge case

        int k = 1; // index for unique elements
        for (int i = 1; i < n; i++) {
            if (num[i] != num[i - 1]) { 
                num[k] = num[i]; // place unique element
                k++;
            }
        }
        return k;
    }
};

int main() {
    vector<int> nums = {1, 1, 2, 2, 3, 3, 4};
    
    Solution sol;
    int k = sol.removeDuplicates(nums);

    cout << "Number of unique elements = " << k << endl;
    cout << "Array after removing duplicates: ";
    for (int i = 0; i < k; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}
