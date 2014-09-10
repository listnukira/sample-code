#include <iostream>

using namespace std;

int removeDuplicates(int A[], int n)
{
    int len = 0;
    for (int i = 0; i < n; i++) {

        if (len == 0 || (A[len - 1] ^ A[i]) != 0) {
            A[len++] = A[i];
        }
    }

    return len;
}

int main(int argc, char const* argv[])
{
    int array1[] = {1, 1, 2, 3, 3};
    int zeroArray[] = {0, 0, 0, 0, 0};

    int len1 = removeDuplicates(array1, sizeof(array1) / sizeof(int));
    for (int i = 0; i < len1; i++) {
        cout << array1[i] << " ";
    }
    cout << endl;

    int len2 = removeDuplicates(zeroArray, sizeof(zeroArray) / sizeof(int));
    for (int i = 0; i < len2; i++) {
        cout << zeroArray[i] << " ";
    }
    cout << endl;
    
    return 0;
}
