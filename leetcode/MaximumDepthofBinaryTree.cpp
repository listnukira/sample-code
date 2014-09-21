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
    int maxDepth(TreeNode *root) {
        if (root == NULL)
            return 0;

        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};


int main(int argc, char const* argv[])
{
    Solution solution;
    struct TreeNode root(0);
    struct TreeNode node1(1), node2(2), node3(3), node4(4);

    root.left = &node1;
    root.right = &node2;
    node1.left = &node3;
    node3.left = &node4;

    cout << solution.maxDepth(&root) << endl;
    
    return 0;
}
