#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode *head) {
        struct ListNode *current = head;

        if (head == NULL)
            return head;

        while (current->next != NULL) {
            if (current->val == current->next->val)
                current->next = current->next->next;
            else
                current = current->next;
        }

        return head;
    }
};


int main(int argc, char const* argv[])
{
    Solution solution;
    struct ListNode *head, *current;
    struct ListNode node1(1);
    struct ListNode node2(1);
    struct ListNode node3(2);
    struct ListNode node4(3);
    struct ListNode node5(3);

    head = &node1;
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node5;

    current = solution.deleteDuplicates(head);
    while (current != NULL) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;

    
    return 0;
}
