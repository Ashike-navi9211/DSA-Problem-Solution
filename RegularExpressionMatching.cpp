
#include <iostream>
#include <string>
#include <vector>
#include <functional>
using namespace std;

class Solution {
public:
    
    bool isMatch(string s, string p) {
        
        int n = s.size(), m = p.size();
        
        vector<vector<int>> memo(n + 1, vector<int>(m + 1, -1));
        
        function<bool(int,int)> dp = [&](int i, int j) -> bool {
            
            if (memo[i][j] != -1) return memo[i][j];
            
            if (j == m) return memo[i][j] = (i == n);
            
            bool firstMatch = (i < n && (s[i] == p[j] || p[j] == '.'));
            
            if (j + 1 < m && p[j + 1] == '*') {
                
                bool ans = dp(i, j + 2) || (firstMatch && dp(i + 1, j));
                
                return memo[i][j] = ans;
                
            } else {
                
                bool ans = firstMatch && dp(i + 1, j + 1);
                
                return memo[i][j] = ans;
            }
        };
        
        return dp(0, 0);
    }
};

int main() {
    
    Solution sol;
    
    cout << sol.isMatch("aa", "a") << endl;
    
    cout << sol.isMatch("aa", "a*") << endl;
    
    cout << sol.isMatch("ab", ".*") << endl;
    
    cout << sol.isMatch("aab", "c*a*b") << endl;
    
    cout << sol.isMatch("mississippi", "mis*is*p*.") << endl;
    
    return 0;
}
