#include <iostream>
#include <climits>
using namespace std;

class Solution {
public:
    
    int reverse(int x) {
        
        int n = x;
        
        long long sum = 0;
        
        while (n != 0) {
            
            int rem = n % 10;
            
            sum = sum * 10 + rem;
            
            if (sum > INT_MAX || sum < INT_MIN) {
                return 0;
            }
            
            n /= 10;
        }
        
        return sum;
    }
};

int main() {
    
    Solution sol;
    
    cout << sol.reverse(123) << endl;
    
    cout << sol.reverse(-123) << endl;
    
    cout << sol.reverse(120) << endl;
    
    cout << sol.reverse(1534236469) << endl;  
    
    return 0;
}
