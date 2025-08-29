 #include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    
    int romanToInt(string s) {
        
        long int sum = 0;
        
        int len = s.size();
        
        for (int i = 0; i < len; i++) {
            
            if (s[i] == 'I' && s[i + 1] == 'V') {
                sum += 4;
                ++i;
            }
            else if (s[i] == 'I' && s[i + 1] == 'X') {
                sum += 9;
                ++i;
            }
            else if (s[i] == 'X' && s[i + 1] == 'L') {
                sum += 40;
                ++i;
            }
            else if (s[i] == 'X' && s[i + 1] == 'C') {
                sum += 90;
                ++i;
            }
            else if (s[i] == 'C' && s[i + 1] == 'D') {
                sum += 400;
                ++i;
            }
            else if (s[i] == 'C' && s[i + 1] == 'M') {
                sum += 900;
                ++i;
            }
            else {
                switch (s[i]) {
                    
                    case 'I': sum += 1; break;
                    case 'V': sum += 5; break;
                    case 'X': sum += 10; break;
                    case 'L': sum += 50; break;
                    case 'C': sum += 100; break;
                    case 'D': sum += 500; break;
                    case 'M': sum += 1000; break;
                }
            }
        }
        
        return sum;
    }
};

int main() {
    
    Solution sol;
    
    cout << sol.romanToInt("III") << endl;
    
    cout << sol.romanToInt("LVIII") << endl;
    
    cout << sol.romanToInt("MCMXCIV") << endl;
    
    return 0;
}
