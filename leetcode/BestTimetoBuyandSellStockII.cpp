#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int len = prices.size();
        int totalProfit = 0;

        for (int i = 0; i < len - 1; i++) {
            if (prices[i + 1] > prices[i])
                totalProfit += prices[i + 1] - prices[i];
        }

        return totalProfit;
    }
};

int main(int argc, char const* argv[])
{
    Solution solution;
    vector<int> prices = {1, 101, 2, 102};

    cout << solution.maxProfit(prices) << endl;
    
    return 0;
}
