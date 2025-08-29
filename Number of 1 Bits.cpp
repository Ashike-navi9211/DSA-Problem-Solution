
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while (n) {
            count += n & 1;
            n >>= 1;
        }
        return count;
    }
};

int main() {
    Solution sol;
    uint32_t n = 11;
    cout << "Number of 1 Bits: " << sol.hammingWeight(n) << endl;
    return 0;
}
