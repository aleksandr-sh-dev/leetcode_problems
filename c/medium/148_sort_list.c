#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};


void merge(struct ListNode **nodes, int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    struct ListNode *left_nodes[n1], *right_nodes[n2];

    for (i = 0; i < n1; i++) {
        left_nodes[i] = nodes[left + i];
    }

    for (j = 0; j < n2; j++) {
        right_nodes[j] = nodes[mid + 1 + j];
    }

    i = 0;
    j = 0;
    k = left;

    while (i < n1 && j < n2) {
        if (left_nodes[i]->val <= right_nodes[j]->val) {
            nodes[k] = left_nodes[i];
            i++;
        } else {
            nodes[k] = right_nodes[j];
            j++;
        }
        nodes[k]->next = NULL;
        k++;
    }

    while (i < n1) {
        nodes[k] = left_nodes[i];
        nodes[k]->next = NULL;
        i++;
        k++;
    }

    while (j < n2) {
        nodes[k] = right_nodes[j];
        nodes[k]->next = NULL;
        j++;
        k++;
    }
}

void mergeSort(struct ListNode **nodes, int left, int right) {
    if (left < right) {
        int mid = (right + left) / 2;

        mergeSort(nodes, left, mid);
        mergeSort(nodes, mid + 1, right);

        merge(nodes, left, mid, right);
    }
}

struct ListNode* sortList(struct ListNode* head) {
    if (head == NULL) {
        return NULL;
    }

    if (head->next == NULL) {
        return head;
    }

    struct ListNode** nodes = malloc(sizeof(struct ListNode *) * 50000);
    struct ListNode *curr = head;
    int nodes_idx = 0;

    // Fill array of nodes
    while (curr != NULL) {
        nodes[nodes_idx++] = curr;
        curr = curr->next;
    }

    // Merge sort to sort nodes in ascending order
    mergeSort(nodes, 0, (nodes_idx - 1));
    
    int merged_idx = -1;
    struct ListNode *reconstructed = NULL;
    reconstructed = nodes[++merged_idx];
    head = reconstructed;

    while (merged_idx < (nodes_idx - 1)) {
        reconstructed->next = nodes[++merged_idx];
        reconstructed = reconstructed->next;
    }

    free(nodes);

    return head;
}
