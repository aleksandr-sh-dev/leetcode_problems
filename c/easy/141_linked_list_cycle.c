#include <stdbool.h>

#include "../../libs/uthash/src/uthash.h"
 
#define SOLUTION_HASH_TABLE (1) // O(n) memory and time
#define SOLUTION_FLOYDS     (2) // O(1) memory and O(n) time

#define SOLUTION SOLUTION_FLOYDS

struct ListNode {
    int val;
    struct ListNode *next;
};

#if SOLUTION == SOLUTION_FLOYDS
bool hasCycle(struct ListNode *head) {
    if (head == NULL) {
        return false;
    }

    struct ListNode *slow = head;
    struct ListNode *fast = head;

    while(fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;

        if(slow == fast) {
            return true;
        }
    }

    return false;
}
#endif // SOLUTION_FLOYDS

#if SOLUTION == SOLUTION_HASH_TABLE
struct hashTable {
    struct ListNode *key;
    UT_hash_handle hh;
} *hashTable = NULL, *item, *tmpItem;

bool hasCycle(struct ListNode *head) {
    if (head == NULL) {
        return false;
    }

    while(head->next != NULL) {
        HASH_FIND_PTR(hashTable, &head, item);

        if (item != NULL) {
            HASH_ITER(hh, hashTable, item, tmpItem) {
                HASH_DEL(hashTable, item);
                free(item);
            }
            return true;
        } else {
            item = malloc(sizeof(struct hashTable));
            item->key = head;
            HASH_ADD_PTR(hashTable, key, item);
            head = head->next;
        }
    }

    HASH_ITER(hh, hashTable, item, tmpItem) {
        HASH_DEL(hashTable, item);
        free(item);
    }

    return false;
}
#endif // SOLUTION_HASH_TABLE
