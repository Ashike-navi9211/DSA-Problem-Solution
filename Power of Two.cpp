#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && (n & (n-1)) == 0;
    }
};

int main() {
    Solution sol;
    int n = 16;
    cout << n << " is power of two? " << (sol.isPowerOfTwo(n) ? "Yes" : "No") << endl;
    return 0;
}
