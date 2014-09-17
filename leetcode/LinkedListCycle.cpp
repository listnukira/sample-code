#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        struct ListNode* fast = head;
        struct ListNode* slow = head;

        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;

            if (fast == slow)
                return true;
        }

        return false;
    }
};


int main(int argc, char const* argv[])
{
    Solution solution;
    struct ListNode* head;
    struct ListNode node1(1);
    struct ListNode node2(2);
    struct ListNode node3(3);
    struct ListNode node4(4);

    head = &node1;
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;

    cout << solution.hasCycle(head) << endl;

    
    return 0;
}
