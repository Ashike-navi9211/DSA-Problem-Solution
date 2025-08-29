#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        vector<int> merged;
        
        merged.reserve(nums1.size() + nums2.size());
        
        merged.insert(merged.end(), nums1.begin(), nums1.end());
        
        merged.insert(merged.end(), nums2.begin(), nums2.end());
        
        sort(merged.begin(), merged.end());
        
        int n = merged.size();
        
        if (n % 2 == 1) {
            return merged[n / 2];
        } else {
            return (merged[n / 2 - 1] + merged[n / 2]) / 2.0;
        }
    }
};

int main() {
    
    Solution sol;
    
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};
    
    cout << sol.findMedianSortedArrays(nums1, nums2) << endl;
    
    return 0;
}
