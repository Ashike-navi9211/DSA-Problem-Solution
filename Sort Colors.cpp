#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low=0, mid=0, high=nums.size()-1;
        while(mid<=high){
            if(nums[mid]==0) swap(nums[low++], nums[mid++]);
            else if(nums[mid]==1) mid++;
            else swap(nums[mid], nums[high--]);
        }
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i=0;i<n;i++) cin >> nums[i];
    Solution sol;
    sol.sortColors(nums);
    for(int val: nums) cout << val << " ";
}
