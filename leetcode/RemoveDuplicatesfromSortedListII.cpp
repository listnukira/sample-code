#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL) {}
};

ListNode* deleteDuplicates(ListNode *head)
{
    struct ListNode fakeHead(0);
    struct ListNode *current = head, *newList = &fakeHead;
    bool isRepeat = false;

    if (head == NULL)
        return head;

    while (current->next != NULL) {
        if (current->val == current->next->val) {
            current->next = current->next->next;
            isRepeat = true;
        } else if (isRepeat == true) {
            current = current->next;
            isRepeat = false;
        } else {
            newList->next = current;
            newList = current;
            current = current->next;
        }
    }

    if (isRepeat == true)
        newList->next = NULL;
    else
        newList->next = current;

    return fakeHead.next;
}

int main(int argc, char const* argv[])
{
    struct ListNode *head, *current;
    struct ListNode node1(1);
    struct ListNode node2(1);
    struct ListNode node3(2);
    struct ListNode node4(3);
    struct ListNode node5(3);
    struct ListNode node6(4);
    struct ListNode node7(4);
    struct ListNode node8(5);

    head = &node1;
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node5;
    node5.next = &node6;
    node6.next = &node7;
    node7.next = &node8;

    /* before */
    current = head;
    while (current != NULL) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;

    current = deleteDuplicates(head);

    /* after */
    while (current != NULL) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;

    
    return 0;
}
