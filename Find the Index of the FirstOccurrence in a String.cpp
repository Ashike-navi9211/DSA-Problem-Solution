#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();

        if (m == 0) return 0;  // empty needle case

        if (n == m && haystack == needle) {
            return 0;
        }

        for (int i = 0; i <= n - m; i++) {
            if (needle == haystack.substr(i, m)) {
                return i;
            }
        }
        return -1;
    }
};

int main() {
    Solution sol;

    string haystack, needle;
    cout << "Enter haystack string: ";
    cin >> haystack;
    cout << "Enter needle string: ";
    cin >> needle;

    int index = sol.strStr(haystack, needle);

    if (index != -1)
        cout << "First occurrence of \"" << needle 
             << "\" in \"" << haystack 
             << "\" is at index: " << index << endl;
    else
        cout << "Substring \"" << needle << "\" not found in \"" 
             << haystack << "\"." << endl;

    return 0;
}
