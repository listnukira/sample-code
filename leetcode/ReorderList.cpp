#include <iostream>
#include <stack>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL) {}
};

class Solution {
public:
    void reorderList(ListNode *head) {
        stack<struct ListNode *> s;
        struct ListNode *fast, *slow;

        if (head == NULL)
            return;

        fast = slow = head;
        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }

        /* push seconde half to stack */
        while (slow != NULL) {
            s.push(slow);
            slow = slow->next;
        }

        fast = head;
        while (!s.empty()) {
            s.top()->next = fast->next;
            fast->next = s.top();
            s.pop();
            fast = fast->next->next;
        }
        fast->next = NULL;
    }
};

int main(int argc, char const* argv[])
{
    Solution solution;
    struct ListNode *head, *cur;
    struct ListNode node1(1);
    struct ListNode node2(2);
    struct ListNode node3(3);
    struct ListNode node4(4);

    head = &node1;
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;

    /* before */
    cur = head;
    while (cur != NULL) {
        cout << cur->val << "";
        cur = cur->next;
    }
    cout << endl;

    solution.reorderList(head);

    cur = head;
    while (cur != NULL) {
        cout << cur->val << "";
        cur = cur->next;
    }
    cout << endl;
    
    return 0;
}
