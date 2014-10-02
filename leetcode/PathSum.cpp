#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool hasPathSum(TreeNode *root, int sum) {
        if (root == NULL)
            return false;

        if (root->left == NULL && root->right == NULL)
            return (sum - root->val == 0);

        return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
    }
};

int main(int argc, char const* argv[])
{
    Solution solution;
    struct TreeNode root(5);
    struct TreeNode node1(4), node2(8), node3(11), node4(13);
    struct TreeNode node5(4), node6(7), node7(2), node8(1);

    root.left = &node1;
    root.right = &node2;
    node1.left = &node3;
    node2.left = &node4;
    node2.right = &node5;
    node3.left = &node6;
    node3.right = &node7;
    node5.right = &node8;

    cout << solution.hasPathSum(&root, 22) << endl;

    return 0;
}
