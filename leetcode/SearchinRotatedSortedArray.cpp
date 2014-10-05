#include <iostream>

using namespace std;

class Solution {
public:
    int search(int A[], int n, int target) {
        int left = 0, right = n - 1;

        while (left <= right) {
            int middle = (left + right) / 2;

            if (A[middle] == target)
                return middle;

            if (A[left] <= A[middle]) {
                if (target >= A[left] && target <= A[middle]) {
                    right = middle - 1;
                } else {
                    left = middle + 1;
                }
            } else {
                if (target >= A[middle] && target <= A[right]) {
                    left = middle + 1;
                } else {
                    right = middle - 1;
                }
            }
        }

        return -1;
    }
};

int main(int argc, char const* argv[])
{
    Solution solution;

    int A[] = {4, 5, 6, 7, 0, 1, 2};

    cout << solution.search(A, sizeof(A) / sizeof(int), 0) << endl;
    
    return 0;
}
