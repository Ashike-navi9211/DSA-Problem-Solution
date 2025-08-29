#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if(n <= 2) return n;
        int a = 1, b = 2;
        for(int i=3; i<=n; i++){
            int temp = a + b;
            a = b;
            b = temp;
        }
        return b;
    }
};

int main() {
    Solution sol;
    int n;
    cin >> n;
    cout << sol.climbStairs(n) << endl;
}
