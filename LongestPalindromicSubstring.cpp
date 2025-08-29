#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    
    bool isPalindrome(const string &s, int left, int right) {
        
        while (left < right) {
            
            if (s[left] != s[right]) return false;
            
            left++;
            
            right--;
        }
        
        return true;
    }
    
    string longestPalindrome(string s) {
        
        int n = s.size();
        
        for (int len = n; len > 0; len--) {
            
            for (int start = 0; start + len - 1 < n; start++) {
                
                int end = start + len - 1;
                
                if (isPalindrome(s, start, end)) {
                    
                    return s.substr(start, len);
                }
            }
        }
        
        return "";
    }
};

int main() {
    
    Solution sol;
    
    string s = "babad";
    
    cout << sol.longestPalindrome(s) << endl;
    
    return 0;
}
