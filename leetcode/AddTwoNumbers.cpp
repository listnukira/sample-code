#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *curL1 = l1, *curL2 = l2;
        int sum = 0;

        ListNode *fakeHead = new ListNode(0);
        ListNode *cur = fakeHead;
        while (curL1 != NULL || curL2 != NULL) {
            sum /= 10;

            if (curL1 != NULL) {
                sum += curL1->val;
                curL1 = curL1->next;
            }

            if (curL2 != NULL) {
                sum += curL2->val;
                curL2 = curL2->next;
            }

            cur->next = new ListNode(sum % 10);
            cur = cur->next;
        }

        if (sum > 9)
            cur->next = new ListNode(1);

        return fakeHead->next;
    }
};


int main(int argc, char const* argv[])
{
    Solution solution;
    struct ListNode* cur;
    struct ListNode node1(9), node2(9), node3(9);

    node1.next = &node2;
    node2.next = &node3;

    cur = solution.addTwoNumbers(&node1, &node1);
    while (cur != NULL) {
        cout << cur->val << " ";
        cur = cur->next;
    }
    cout << endl;

    return 0;
}
