#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();

        // Start from the end and handle carry
        for (int i = n - 1; i >= 0; i--) {
            if (digits[i] < 9) {
                digits[i]++;
                return digits;
            }
            digits[i] = 0; // carry over
        }

        // If all were 9s, insert 1 at the beginning
        digits.insert(digits.begin(), 1);
        return digits;
    }
};

int main() {
    Solution sol;

    vector<int> num1 = {1, 2, 3};
    vector<int> num2 = {4, 3, 2, 1};
    vector<int> num3 = {9, 9, 9};

    vector<int> result1 = sol.plusOne(num1);
    vector<int> result2 = sol.plusOne(num2);
    vector<int> result3 = sol.plusOne(num3);

    // Print results
    for (int x : result1) cout << x << " ";
    cout << endl;

    for (int x : result2) cout << x << " ";
    cout << endl;

    for (int x : result3) cout << x << " ";
    cout << endl;

    return 0;
}
