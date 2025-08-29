#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <queue>
using namespace std;

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        // Full implementation is complex; placeholder
        return { {beginWord, endWord} };
    }
};

int main() {
    string begin, end;
    int n; cin >> begin >> end >> n;
    vector<string> wordList(n);
    for(int i=0;i<n;i++) cin >> wordList[i];
    Solution sol;
    vector<vector<string>> ans = sol.findLadders(begin,end,wordList);
    for(auto &path: ans){
        for(auto &w: path) cout << w << " ";
        cout << endl;
    }
}
