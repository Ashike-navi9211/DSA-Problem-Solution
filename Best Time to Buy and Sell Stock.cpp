#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX, profit=0;
        for(int price: prices){
            minPrice = min(minPrice, price);
            profit = max(profit, price-minPrice);
        }
        return profit;
    }
};

int main() {
    int n; cin >> n;
    vector<int> prices(n);
    for(int i=0;i<n;i++) cin >> prices[i];
    Solution sol;
    cout << sol.maxProfit(prices);
}
