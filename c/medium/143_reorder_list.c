#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

void reorderList(struct ListNode* head) {
    if (head->next == NULL) {
        return;
    }

    struct ListNode* slow = head;
    struct ListNode* fast = head;
    struct ListNode *pre_slow = NULL;
    int list_mid_num = 0;

    // Find list middle node
    while(fast != NULL && fast->next != NULL) {
        pre_slow = slow;
        slow = slow->next;
        fast = fast->next->next;
        list_mid_num++;
    }

    // Divide 2 lists - first half and the second half
    pre_slow->next = NULL;

    struct ListNode *next;
    struct ListNode *prev = NULL;
    
    // Reverse second half in place
    while(slow != NULL) {
        next = slow->next;
        slow->next = prev;
        prev = slow;
        slow = next;
    }

    // Merge first half with reversed second half
    while(head != NULL && prev != NULL) {
        struct ListNode *head_next = head->next;
        struct ListNode *slow_next = prev->next;

        head->next = prev;

        if (head_next == NULL) {
            break;
        }

        prev->next = head_next;

        head = head_next;
        prev = slow_next;
    }
}
