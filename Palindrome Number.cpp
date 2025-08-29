#include <iostream>
using namespace std;

class Solution {
public:
    
    bool isPalindrome(int x) {
        
        if (x < 0) {
            return false;
        }
        
        long long int num = 0;
        
        int a = x;
        
        while (x != 0) {
            
            int rem = x % 10;
            
            num = num * 10 + rem;
            
            x = x / 10;
        }
        
        if (num == a) {
            return true;
        }
        
        return false;
    }
};

int main() {
    
    Solution sol;
    
    cout << sol.isPalindrome(121) << endl;
    
    cout << sol.isPalindrome(-121) << endl;
    
    cout << sol.isPalindrome(10) << endl;
    
    cout << sol.isPalindrome(1221) << endl;
    
    return 0;
}
