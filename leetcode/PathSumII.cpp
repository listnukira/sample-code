#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector< vector<int> > pathSum(TreeNode *root, int sum) {
        vector< vector<int> > allPath, leftPath, rightPath;

        if (root == NULL)
            return allPath;

        path.push_back(root->val);

        if ((sum - root->val) == 0 && root->left == NULL && root->right == NULL)
            allPath.push_back(path);

        leftPath = pathSum(root->left, sum - root->val);
        rightPath = pathSum(root->right, sum - root->val);

        for (auto&& v : leftPath)
            allPath.push_back(v);

        for (auto&& v : rightPath)
            allPath.push_back(v);

        path.pop_back();

        return allPath;
    }

private:
    vector<int> path;
};

int main(int argc, char const* argv[])
{
    Solution solution;
    struct TreeNode root(5);
    struct TreeNode node1(4), node2(8), node3(11), node4(13);
    struct TreeNode node5(4), node6(7), node7(2), node8(1), node9(5);

    root.left = &node1;
    root.right = &node2;
    node1.left = &node3;
    node2.left = &node4;
    node2.right = &node5;
    node3.left = &node6;
    node3.right = &node7;
    node5.left = &node9;
    node5.right = &node8;

    for (auto&& vec : solution.pathSum(&root, 22)) {
        for (auto&& var : vec) {
            cout << var << " ";
        }
        cout <<endl;
    }

    return 0;
}
