#include <stddef.h>
#include <stdbool.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

void addNumToList(struct ListNode **head, struct ListNode **tail, int value) {
    struct ListNode *new = (struct ListNode*)malloc(sizeof(struct ListNode));

    new->val = value;
    new->next = NULL;

    if (*head == NULL) {
        *head = new;
        *tail = new;
    } else {
        (*tail)->next = new;
        *tail = new;
    }
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *result = NULL;
    struct ListNode *tail = NULL;

    int saved_value = 0;
    int l1_val = 0;
    int l2_val = 0;
    int new_val = 0;

    bool l1_ended = false;
    bool l2_ended = false;

    while (!l1_ended || !l2_ended) {
        if (!l1_ended) {
            l1_val = l1->val;
        }

        if (!l2_ended) {
            l2_val = l2->val;
        }

        new_val = l1_val + l2_val + saved_value;

        if (new_val / 10 != 0) {
            saved_value = 1;
            new_val = new_val % 10;
        } else {
            saved_value = 0;
        }

        addNumToList(&result, &tail, new_val);

        l1_val = 0;
        l2_val = 0;
        
        if (l1->next != NULL) {
            l1 = l1->next;
        } else {
            l1_ended = true;
        }

        if (l2->next != NULL) {
            l2 = l2->next;
        } else {
            l2_ended = true;
        }
    }

    if (saved_value != 0) {
        addNumToList(&result, &tail, saved_value);
    }

    return result;
}
