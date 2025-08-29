#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long flowerGame(int n, int m) {
        long long oddN = (n + 1) / 2;
        long long evenN = n / 2;
        long long oddM = (m + 1) / 2;
        long long evenM = m / 2;
        return oddN * evenM + evenN * oddM;
    }
};

int main() {
    Solution s;
    int n, m;
    cin >> n >> m;
    cout << s.flowerGame(n, m) << endl;
    return 0;
}
