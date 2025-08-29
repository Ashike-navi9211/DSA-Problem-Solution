#include <iostream>
#include <string>
#include <climits>
using namespace std;

class Solution {
public:
    
    int myAtoi(string s) {
        
        int mus = 1, count = 0, i = 0, start = 0;
        
        long long int k = 0;
        
        for (int j = 0; j < s.size(); j++) {
            
            if (s[j] == ' ') {
                k += 1;
            } else {
                break;
            }
        }
        
        if (!s.empty() && s[k] == '-') {
            mus = -1;
            k++;
        } else if (!s.empty() && s[k] == '+') {
            k++;
        }
        
        start = k;
        
        i = k;
        
        for (; i < s.size(); i++) {
            
            if (isdigit(s[i])) {
                count++;
            } else {
                break;
            }
        }
        
        if (count > 0) {
            
            long long val = 0;
            
            for (int idx = start; idx < start + count; idx++) {
                
                val = val * 10 + (s[idx] - '0');
                
                if (mus == 1 && val > INT_MAX) return INT_MAX;
                
                if (mus == -1 && -val < INT_MIN) return INT_MIN;
            }
            
            return (int)(val * mus);
        }
        
        return 0;
    }
};

int main() {
    
    Solution sol;
    
    cout << sol.myAtoi("42") << endl;
    
    cout << sol.myAtoi("   -42") << endl;
    
    cout << sol.myAtoi("4193 with words") << endl;
    
    cout << sol.myAtoi("words and 987") << endl;
    
    cout << sol.myAtoi("-91283472332") << endl;
    
    return 0;
}
