#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int longest=0;
        for(int num: nums){
            if(s.find(num-1)==s.end()){
                int curr=num, len=1;
                while(s.find(curr+1)!=s.end()){ curr++; len++; }
                longest=max(longest,len);
            }
        }
        return longest;
    }
};

int main() {
    int n; cin >> n;
    vector<int> nums(n);
    for(int i=0;i<n;i++) cin >> nums[i];
    Solution sol;
    cout << sol.longestConsecutive(nums);
}
