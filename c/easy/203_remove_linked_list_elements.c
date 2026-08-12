#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode *next;
    struct ListNode *cur = head;

    while (head != NULL && head->val == val) {
        head = head->next;
    }

    while (cur != NULL) {
        if (cur->next == NULL) {
            break;
        }
        
        if (cur->next->val == val) {
            if (cur->next->next != NULL) {
                next = cur->next->next;
            } else {
                next = NULL;
            }
            
            cur->next = next;
        } else {
            cur = cur->next;
        }
    }

    return head;
}
