#include <iostream>

using namespace std;

class Solution {
public:
    bool search(int A[], int n, int target) {
        int left = 0, right = n - 1;

        while (left <= right) {
            int middle = (left + right) / 2;

            if (A[middle] == target)
                return true;

            if (A[left] < A[middle]) {
                if (target >= A[left] && target <= A[middle]) {
                    right = middle - 1;
                } else {
                    left = middle + 1;
                }
            } else if (A[left] > A[middle]) {
                if (target >= A[middle] && target <= A[right]) {
                    left = middle + 1;
                } else {
                    right = middle - 1;
                }
            } else {
                left++;
            }
        }

        return false;
    }
};

int main(int argc, char const* argv[])
{
    Solution solution;

    int A[] = {1, 3, 1, 1, 1};

    cout << solution.search(A, sizeof(A) / sizeof(int), 3) << endl;
    
    return 0;
}
