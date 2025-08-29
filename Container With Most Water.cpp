#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    
    int maxArea(vector<int>& height) {
        
        int l = 0, r = height.size() - 1;
        
        int best = 0;
        
        while (l < r) {
            
            int ht = min(height[l], height[r]);
            
            int area = ht * (r - l);
            
            best = max(best, area);
            
            if (height[l] < height[r]) {
                l++;
            } else {
                r--;
            }
        }
        
        return best;
    }
};

int main() {
    
    Solution sol;
    
    vector<int> h1 = {1,8,6,2,5,4,8,3,7};
    
    cout << sol.maxArea(h1) << endl;
    
    vector<int> h2 = {1,1};
    
    cout << sol.maxArea(h2) << endl;
    
    return 0;
}
