#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};
 
struct ListNode* reverseInPlace(struct ListNode *head, int left, int right) {
    struct ListNode *next;
    struct ListNode *prev = NULL;

    int node_cnt = left;

    while (node_cnt <= right) {
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;

        node_cnt++;
    }

    return prev;
}

struct ListNode* reverseBetween(struct ListNode* head, int left, int right) {
    if (head == NULL) {
        return NULL;
    }
        
    if (right == 1) {
        return head;
    }
    
    struct ListNode *curr = head;
    struct ListNode *tmp = head;
    struct ListNode *saved = NULL;
    int node_num = 1;

    while (tmp != NULL) {
        // Node is the right boundary
        if (node_num == right) {
            if (tmp->next != NULL) {
                saved = tmp->next;
            }
            break;
        }
        node_num++;
        tmp = tmp->next;
    }

    node_num = 1;

    while (curr != NULL) {
        // Next node is the left boundary
        if (left != 1 && (node_num + 1) == left) {
            curr->next = reverseInPlace(curr->next, node_num + 1, right);
        } else if (left == 1 && node_num == left) {
            struct ListNode *old_head = head;
            head = reverseInPlace(head, left, right);
            old_head->next = saved;
            break;
        }

        if (node_num == right) {
            if (saved != NULL) {
                curr->next = saved;
            } else {
                curr->next = NULL;
            }   
        }

        node_num++;
        curr = curr->next;
    }

    return head;
}
