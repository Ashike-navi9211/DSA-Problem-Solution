#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> pos;
        int maxLenght = 0, start = 0;
        for (int end = 0; end < s.size(); end++) {
            if (pos.find(s[end]) != pos.end()) {
                start = max(pos[s[end]] + 1, start);
            }
            pos[s[end]] = end;
            maxLenght = max(maxLenght, end - start + 1);
        }
        return maxLenght;
    }
};

int main() {
    Solution sol;
    string s = "abcabcbb";
    cout << sol.lengthOfLongestSubstring(s) << endl;
    return 0;
}
