#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        // Lambda to calculate gain
        auto gain = [](int pass, int total) {
            return (double)(pass + 1) / (total + 1) - (double)pass / total;
        };

        // Max heap: {gain, pass, total}
        priority_queue<tuple<double,int,int>> pq;
        for (auto &c : classes) {
            pq.push({gain(c[0], c[1]), c[0], c[1]});
        }

        // Distribute extra students
        while (extraStudents--) {
            auto [g, pass, total] = pq.top();
            pq.pop();
            pass++, total++;
            pq.push({gain(pass, total), pass, total});
        }

        // Compute final average
        double sum = 0.0;
        while (!pq.empty()) {
            auto [g, pass, total] = pq.top();
            pq.pop();
            sum += (double)pass / total;
        }

        return sum / classes.size();
    }
};

int main() {
    Solution sol;

    // Example input
    int n, extraStudents;
    cout << "Enter number of classes: ";
    cin >> n;

    cout << "Enter number of extra students: ";
    cin >> extraStudents;

    vector<vector<int>> classes(n, vector<int>(2));
    cout << "Enter pass and total students for each class:\n";
    for (int i = 0; i < n; i++) {
        cin >> classes[i][0] >> classes[i][1];
    }

    double result = sol.maxAverageRatio(classes, extraStudents);
    cout << fixed << setprecision(6);
    cout << "Maximum average pass ratio: " << result << endl;

    return 0;
}
