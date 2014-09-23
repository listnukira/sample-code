#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode *head, int m, int n) {
        struct ListNode *reverseHead = NULL, *reverseTail = NULL;
        struct ListNode *connHead = NULL, *connTail = NULL;
        struct ListNode *cur = NULL;

        cur = head;
        for (int i = 1; i <= n; i++) {
            if (i == m)
                reverseTail = cur;

            if (i >= m && i <= n) {
                connTail = cur->next;
                cur->next = reverseHead;
                reverseHead = cur;
                cur = connTail;
            } else {
                connHead = cur;
                cur = cur->next;
            }
        }

        if (connHead != NULL)
            connHead->next = reverseHead;

        reverseTail->next = connTail;

        return (m == 1) ? reverseHead : head;
    }
};


int main(int argc, char const* argv[])
{
    Solution solution;
    struct ListNode *head, *cur;
    struct ListNode *ans;
    struct ListNode node1(1), node2(2), node3(3), node4(4), node5(5);

    head = &node1;
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node5;

    cur = head;
    while (cur != NULL) {
        cout << cur->val << " ";
        cur = cur->next;
    }
    cout << endl;

    cur = solution.reverseBetween(head, 2, 5);
    
    while (cur != NULL) {
        cout << cur->val << " ";
        cur = cur->next;
    }
    cout << endl;

    return 0;
}
