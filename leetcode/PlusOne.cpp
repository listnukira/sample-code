#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        vector<int> result;
        vector<int>::iterator it = result.begin();

        int carry = 1;
        for (int i = digits.size() - 1; i >= 0 ; i--) {
            if (digits[i] + carry == 10) {
                it = result.insert(it, 0);
            } else {
                it = result.insert(it, digits[i] + carry);
                carry = 0;
            }
        }

        if (carry == 1)
            result.insert(it, 1);

        return result;
    }
};

int main(int argc, char const* argv[])
{
    Solution solution;
    vector<int> digits = {9, 9, 9, 9};

    for (auto&& digit : solution.plusOne(digits)) {
        cout << digit << " ";
    }
    cout << endl;
    
    return 0;
}
