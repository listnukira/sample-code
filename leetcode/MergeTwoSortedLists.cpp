#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *fakeHead = new ListNode(0);
        ListNode *head = fakeHead;

        while (l1 != NULL && l2 != NULL) {
            if (l2->val > l1->val) {
                fakeHead->next = l1;
                l1 = l1->next;
            } else {
                fakeHead->next = l2;
                l2 = l2->next;
            }

            fakeHead = fakeHead->next;
        }

        fakeHead->next = (l1 == NULL) ? l2 : l1;

        return head->next;
    }
};


int main(int argc, char const* argv[])
{
    Solution solution;
    struct ListNode *l1, *l2;
    struct ListNode node1(1), node2(2), node3(3), node4(4);
    
    node2.next = &node4;
    node1.next = &node3;

    l1 = &node2; // 2 4
    l2 = &node1; // 1 3
    
    struct ListNode *cur = solution.mergeTwoLists(l1, l2);

    while (cur != NULL) {
        cout << cur->val << endl;
        cur = cur->next;
    }
    return 0;
}
