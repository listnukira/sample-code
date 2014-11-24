#include <iostream>

using namespace std;

class Solution {
public:
    int jump(int A[], int n) {
        int idx = 0, nextIdx = 0;
        int step, jumpNum = 1;

        if (n == 1)
            return 0;

        while (A[nextIdx] + nextIdx < n - 1) {
            step = A[nextIdx];
            idx = nextIdx;
            for (int i = 1; i <= step; i++) {
                if (A[idx + i] > step - i && A[idx + i] + idx + i > A[nextIdx] + nextIdx)
                    nextIdx = idx + i;
            }

            ++jumpNum;
        }

        return jumpNum;
    }
};

int main(int argc, char const* argv[])
{
    Solution solution;

    int A[] = {5, 9, 3, 2, 1, 0, 2, 3, 3, 1, 0, 0};

    cout << solution.jump(A, sizeof(A)/ sizeof(int)) << endl;
    
    return 0;
}
