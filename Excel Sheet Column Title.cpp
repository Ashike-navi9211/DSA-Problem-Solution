#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string convertToTitle(int columnNumber) {
        string result = "";
        while (columnNumber > 0) {
            columnNumber--;
            result += 'A' + (columnNumber % 26);
            columnNumber /= 26;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

int main() {
    Solution sol;
    int num = 28;
    cout << "Column Title: " << sol.convertToTitle(num) << endl;
    return 0;
}
