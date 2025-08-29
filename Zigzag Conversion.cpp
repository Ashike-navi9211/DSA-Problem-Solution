#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    
    string convert(string s, int numRows) {
        
        vector<string> r(numRows, "");
        
        vector<int> t;
        
        string result;
        
        int n = s.size();
        
        for (int i = 0; i < numRows; i++) {
            t.push_back(i);
        }
        
        for (int i = numRows - 2; i > 0; i--) {
            t.push_back(i);
        }
        
        for (int i = 0; i < s.size(); i++) {
            
            int row_index = t[i % t.size()];
            
            r[row_index] += s[i];
        }
        
        for (int i = 0; i < r.size(); i++) {
            
            result += r[i];
        }
        
        return result;
    }
};

int main() {
    
    Solution sol;
    
    string s = "PAYPALISHIRING";
    
    int numRows = 3;
    
    cout << sol.convert(s, numRows) << endl;
    
    return 0;
}
