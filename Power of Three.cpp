#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n <= 0) return false;
        while(n % 3 == 0) n /= 3;
        return n == 1;
    }
};

int main() {
    Solution sol;
    int n = 27;
    cout << n << " is power of three? " << (sol.isPowerOfThree(n) ? "Yes" : "No") << endl;
    return 0;
}
