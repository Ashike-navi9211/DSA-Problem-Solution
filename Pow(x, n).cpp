#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        long long exp = n; // to handle INT_MIN safely
        if (exp < 0) {
            x = 1 / x;
            exp = -exp;
        }
        double result = 1.0;
        while (exp > 0) {
            if (exp % 2 == 1) { // if odd power
                result *= x;
            }
            x *= x;  // square the base
            exp /= 2; // divide exponent by 2
        }
        return result;
    }
};

int main() {
    Solution sol;
    double x;
    int n;

    cout << "Enter base (x): ";
    cin >> x;

    cout << "Enter exponent (n): ";
    cin >> n;

    double result = sol.myPow(x, n);
    cout << x << "^" << n << " = " << result << endl;

    return 0;
}
