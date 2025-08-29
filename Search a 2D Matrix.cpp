#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if(m==0) return false;
        int n = matrix[0].size();
        int low = 0, high = m*n - 1;
        while(low <= high){
            int mid = (low + high)/2;
            int val = matrix[mid/n][mid%n];
            if(val == target) return true;
            else if(val < target) low = mid+1;
            else high = mid-1;
        }
        return false;
    }
};

int main() {
    int m,n,target;
    cin >> m >> n >> target;
    vector<vector<int>> matrix(m, vector<int>(n));
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            cin >> matrix[i][j];
    Solution sol;
    cout << (sol.searchMatrix(matrix, target) ? "true" : "false") << endl;
}
