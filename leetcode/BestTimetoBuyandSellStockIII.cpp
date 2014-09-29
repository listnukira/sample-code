#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int len = prices.size();
        int profitMax = 0, profitSecond = 0, min = 0, profit = 0;

        for (int i = 0; i < len; i++) {
            if (i == 0 || prices[i] < prices[i - 1]) {
                min = prices[i];
                profit = 0;
                if (profitSecond > profitMax)
                    swap(profitMax, profitSecond);
            } else if (prices[i] - min > profit) {
                profit = prices[i] - min;
                if (profit > profitSecond)
                    profitSecond = profit;
            } else {}
        }

        return profitMax + profitSecond;
    }
};

int main(int argc, char const* argv[])
{
    Solution solution;
    vector<int> prices = {1, 2, 4, 2, 5, 7, 2, 4, 9, 0};

    cout << solution.maxProfit(prices) << endl;
    
    return 0;
}
