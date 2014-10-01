#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int len = prices.size(), maxProfit = 0;

        if (len < 2)
            return 0;

        int low = prices[0];
        int high = prices[len - 1];
        vector<int> profitsHist(len, 0);
        for (int i = 0; i < len; i++) {
            low = min(low, prices[i]);
            maxProfit = max(maxProfit, prices[i] - low);
            profitsHist[i] = maxProfit;
        }

        for (int i = len - 1; i >= 0; i--) {
            high = max(high, prices[i]);
            maxProfit = max(maxProfit, high - prices[i] + profitsHist[i]);
        }

        return maxProfit;
    }

    int maxProfit2(vector<int> &prices) {
        vector<bool> segs(prices.size());
        int maxProfit = 0;

        if (prices.size() == 0)
            return 0;

        for (int transact = 0; transact < 2; transact++) {
            int i0 = 0, c = 0, cmax = 0;
            vector<int> s;

            for (int i = 0; i < prices.size() - 1; i++) {
                if (i > 0 && segs[i] != segs[i - 1]) {
                    i0 = i;
                    c = 0;
                }

                c = c + prices[i + 1] - prices[i];

                if ((!segs[i] && c <= 0) || (segs[i] && c >=0)) {
                    i0 = i + 1;
                    c = 0;
                }
                else if (cmax < abs(c)) {
                    cmax = abs(c);
                    s = {i0, i};
                }
            }

            if (cmax == 0)
                break;

            for (int i = s[0]; i <= s[1]; i++)
                segs[i] = !segs[i];

            maxProfit += cmax;
        }

        return maxProfit;
    }
};

int main(int argc, char const* argv[])
{
    Solution solution;
    vector<int> prices = {1, 2, 4}; // 3
    vector<int> prices2 = {1, 2, 4, 2, 5, 7, 2, 4, 9, 0}; // 13
    vector<int> prices3 = {1, 3, 7, 2, 5, 9, 3, 10, 1, 20}; // 28
    vector<int> prices4 = {6, 1, 3, 2, 4, 7}; // 7
    vector<int> prices5 = {1, 3, 5, 4, 3, 7, 6, 9, 2, 4}; // 10
    vector<int> prices6 = {0, 3, 8, 6, 8, 6, 6, 8, 2, 0, 2, 7}; // 15
    vector<int> prices7 = {8, 3, 6, 2, 8, 8, 8, 4, 2, 0, 7, 2, 9, 4, 9}; // 15

    cout << solution.maxProfit(prices7) << endl;
    
    return 0;
}
