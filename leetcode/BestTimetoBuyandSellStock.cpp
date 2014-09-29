#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int len = prices.size();
        int profit = 0, min = 0;

        for (int i = 0; i < len; i++) {
            if (i == 0 || prices[i] < min) {
                min = prices[i];
            } else if (prices[i] - min > profit) {
                profit = prices[i] - min;
            } else {}
        }

        return profit;
    }
};

int main(int argc, char const* argv[])
{
    Solution solution;
    vector<int> prices = {4, 2, 3, 10};

    cout << solution.maxProfit(prices) << endl;
    
    return 0;
}
