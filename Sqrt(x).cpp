#include <iostream>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        if (x == 0 || x == 1) return x;
        long long left = 1, right = x, ans = 0;

        while (left <= right) {
            long long mid = left + (right - left) / 2;
            if (mid * mid == x) {
                return mid;
            } else if (mid * mid < x) {
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    cout << sol.mySqrt(4) << endl;   // Output: 2
    cout << sol.mySqrt(8) << endl;   // Output: 2
    cout << sol.mySqrt(16) << endl;  // Output: 4
    return 0;
}
