#include <iostream>
#include <vector>

using namespace std;

vector< vector<int> > generate(int numRows)
{
    vector< vector<int> > triangle(numRows);

    if (numRows <= 0)
        return triangle;

    triangle[0].push_back(1);
    for (int i = 1; i < numRows; i++) {

        triangle[i].push_back(1);
        for (int j = 1; j < i; j++) {
            triangle[i].push_back(triangle[i - 1][j - 1] + triangle[i - 1][j]);
        }
        triangle[i].push_back(1);
    }

    return triangle;
}


int main(int argc, char const* argv[])
{
    for (auto&& vint : generate(5)) {
        for (auto&& n : vint) {
            cout << n << " ";
        }
        cout << endl;
    }
    
    return 0;
}
