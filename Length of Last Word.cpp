#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int length = 0;
        int i = s.size() - 1;

        // Ignore trailing spaces
        while (i >= 0 && s[i] == ' ') {
            i--;
        }

        // Count length of last word
        while (i >= 0 && s[i] != ' ') {
            length++;
            i--;
        }

        return length;
    }
};

int main() {
    Solution sol;

    string s1 = "Hello World";
    string s2 = "   fly me   to   the moon  ";
    string s3 = "luffy is still joyboy";
    string s4 = "   "; // edge case: only spaces

    cout << sol.lengthOfLastWord(s1) << endl; // 5
    cout << sol.lengthOfLastWord(s2) << endl; // 4
    cout << sol.lengthOfLastWord(s3) << endl; // 6
    cout << sol.lengthOfLastWord(s4) << endl; // 0

    return 0;
}
