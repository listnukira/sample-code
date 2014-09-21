#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode *head, int k) {
        struct ListNode *cur = head;
        int len = 1;

        if (head == NULL)
            return head;

        while (cur->next != NULL) {
            cur = cur->next;
            len++;
        }
        cur->next = head;

        k = len - (k % len);
        for (int i = 0; i < k; i++)
            cur = cur->next;

        head = cur->next;
        cur->next = NULL;

        return head;
    }
};


int main(int argc, char const* argv[])
{
    Solution solution;
    struct ListNode *head, *cur;
    struct ListNode node1(1), node2(2), node3(3), node4(4);

    head = &node1;
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;

    cur = head;
    while (cur != NULL) {
        cout << cur->val << " ";
        cur = cur->next;
    }
    cout << endl;

    cur = solution.rotateRight(head, 1);

    while (cur != NULL) {
        cout << cur->val << " ";
        cur = cur->next;
    }
    cout << endl;

    
    return 0;
}
