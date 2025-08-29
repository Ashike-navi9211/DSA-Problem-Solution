#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string result = "";
        int i = a.size() - 1;
        int j = b.size() - 1;
        int carry = 0;

        // Process each digit from right to left
        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;

            if (i >= 0) {
                sum += a[i] - '0';
                i--;
            }
            if (j >= 0) {
                sum += b[j] - '0';
                j--;
            }

            result += (sum % 2) + '0';  // append binary digit
            carry = sum / 2;            // update carry
        }

        reverse(result.begin(), result.end());
        return result;
    }
};

int main() {
    Solution sol;

    string a1 = "1010", b1 = "1011";
    string a2 = "11", b2 = "1";
    string a3 = "0", b3 = "0";

    cout << "Result 1: " << sol.addBinary(a1, b1) << endl; // 10101
    cout << "Result 2: " << sol.addBinary(a2, b2) << endl; // 100
    cout << "Result 3: " << sol.addBinary(a3, b3) << endl; // 0

    return 0;
}
