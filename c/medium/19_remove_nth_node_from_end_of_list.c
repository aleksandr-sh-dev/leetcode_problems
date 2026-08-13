#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode **nodes = malloc(sizeof(struct ListNode *) * 30);
    int list_len = 0;

    // Traverse the whole list collecting every node address and calculation the length of the list
    while(head != NULL) {
        nodes[list_len] = head;
        list_len++;
        head = head->next;
    }

    if (list_len == 1 && n == 1) {
        free(nodes);
        return NULL;
    }

    if (n == 1) {
        struct ListNode *temp = nodes[list_len - n - 1];
        temp->next = NULL;
        head = nodes[0];
        free(nodes);
        return head;
    }

    if (list_len == n) {
        head = nodes[1];
        free(nodes);
        return head;
    }

    struct ListNode *temp = nodes[list_len - n - 1];
    struct ListNode *next = nodes[list_len - n + 1];
    temp->next = next;
    head = nodes[0];

    free(nodes);
    return head;
}
