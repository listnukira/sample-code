#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode *head, int n) {
        struct ListNode *first, *second;
        first = second = head;

        for (int i = 0; i < n; i++)
            second = second->next;

        if (second == NULL)
            return first->next;

        while (second->next != NULL) {
            first = first->next;
            second = second->next;
        }

        struct ListNode* delNode = first->next;
        first->next = delNode->next;
        
        return head;
    }
};


int main(int argc, char const* argv[])
{
    Solution solution;
    struct ListNode *head, *current;
    struct ListNode node1(1);
    struct ListNode node2(2);
    struct ListNode node3(3);
    struct ListNode node4(4);

    head = &node1;
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;

    current = solution.removeNthFromEnd(head, 1);
    while (current != NULL) {
        cout << current->val << endl;
        current = current->next;
    }
    
    return 0;
}
