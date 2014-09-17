#include <iostream>

using namespace std;

class Solution {
public:
    int singleNumber(int A[], int n) {
        int ones = 0, twos = 0, threes = 0;

        for (int i = 0; i < n; i++) {
            twos |= (A[i] & ones);
            ones ^= A[i];
            threes = ones & twos;
            ones &= ~threes;
            twos &= ~threes;
        }

        return ones;
    }
};

int main(int argc, char const* argv[])
{
    Solution solution;
    int test1[] = {2};
    int test2[] = {2, 1, 4, 5, 2, 4, 1, 1, 2, 4};
    int test3[] = {-1, 3, -1, -1};

    cout << solution.singleNumber(test1, sizeof(test1) / sizeof(int)) << endl;
    cout << solution.singleNumber(test2, sizeof(test2) / sizeof(int)) << endl;
    cout << solution.singleNumber(test3, sizeof(test3) / sizeof(int)) << endl;
    
    return 0;
}
