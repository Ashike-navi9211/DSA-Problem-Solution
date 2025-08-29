#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t rev = 0;
        for (int i = 0; i < 32; i++) {
            rev <<= 1;
            rev |= (n & 1);
            n >>= 1;
        }
        return rev;
    }
};

int main() {
    Solution sol;
    uint32_t n = 43261596;
    cout << "Reversed Bits: " << sol.reverseBits(n) << endl;
    return 0;
}
