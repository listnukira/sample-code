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
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if (p == NULL || q == NULL)
            return (p == q);

        return (p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};


int main(int argc, char const* argv[])
{
    Solution solution;
    struct TreeNode root1(0), root2(0);
    struct TreeNode node1(1), node2(2), node3(3), node4(4), node5(5);

    cout << solution.isSameTree(NULL, NULL) << endl;

    root1.left = &node1;
    root1.right = &node2;
    node1.left = &node3;
    node1.right = &node4;
    node2.left = &node3;
    node2.right = &node4;

    root2.left = &node1;
    root2.right = &node5;
    node1.left = &node3;
    node1.right = &node4;
    node2.left = &node3;
    node2.right = &node4;

    cout << solution.isSameTree(&root1, &root2) << endl;
    
    return 0;
}
