#include <bits/stdc++.h>
using namespace std;

bool isBadVersion(int version) {
    // Example: version 4 onwards is bad
    return version >= 4;
}

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1, right = n;
        while(left < right) {
            int mid = left + (right - left)/2;
            if(isBadVersion(mid)) right = mid;
            else left = mid + 1;
        }
        return left;
    }
};

int main() {
    Solution sol;
    int n = 5;
    cout << "First Bad Version: " << sol.firstBadVersion(n) << endl;
    return 0;
}
