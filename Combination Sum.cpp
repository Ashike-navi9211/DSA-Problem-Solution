#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int> combination;
        backtrack(candidates, target, 0, combination, result);
        return result;
    }

private:
    void backtrack(const vector<int>& candidates, int target, int start,
                   vector<int>& combination, vector<vector<int>>& result) {
        if (target == 0) {
            result.push_back(combination);
            return;
        }

        for (int i = start; i < candidates.size(); ++i) {
            if (candidates[i] > target) break; // pruning step

            combination.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], i, combination, result);
            combination.pop_back(); // backtrack
        }
    }
};

int main() {
    Solution sol;
    int n, target;

    cout << "Enter number of candidates: ";
    cin >> n;

    vector<int> candidates(n);
    cout << "Enter candidates: ";
    for (int i = 0; i < n; i++) {
        cin >> candidates[i];
    }

    cout << "Enter target: ";
    cin >> target;

    vector<vector<int>> result = sol.combinationSum(candidates, target);

    cout << "\nCombinations that sum to " << target << ":\n";
    for (auto& comb : result) {
        cout << "[ ";
        for (int num : comb) cout << num << " ";
        cout << "]\n";
    }

    return 0;
}
