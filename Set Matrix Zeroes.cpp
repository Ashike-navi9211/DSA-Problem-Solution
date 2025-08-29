#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<bool> row(m, false), col(n, false);

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    row[i] = true;
                    col[j] = true;
                }
            }
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(row[i] || col[j]){
                    matrix[i][j] = 0;
                }
            }
        }
    }
};

int main() {
    int m,n;
    cin >> m >> n;
    vector<vector<int>> matrix(m, vector<int>(n));
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            cin >> matrix[i][j];
    Solution sol;
    sol.setZeroes(matrix);
    for(auto &row: matrix){
        for(auto val: row) cout << val << " ";
        cout << endl;
    }
}
