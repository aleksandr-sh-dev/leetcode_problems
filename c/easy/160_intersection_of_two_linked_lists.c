#include "../../libs/uthash/src/uthash.h"

struct hashTable {
    struct ListNode *key;
    UT_hash_handle hh;
} *hashTable = NULL, *item, *tmpItem;

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    if (headA == NULL || headB == NULL) {
        return NULL;
    }

    struct ListNode *intersection = NULL;

    // Fill up hash table for headA
    while(headA != NULL) {
        item = malloc(sizeof(struct hashTable));
        item->key = headA;
        HASH_ADD_PTR(hashTable, key, item);
        headA = headA->next;
    }

    // Check if the same node appears for headB
    while(headB != NULL) {
        HASH_FIND_PTR(hashTable, &headB, item);
        // Found node where intersection happens
        if (item != NULL) {
            intersection = item->key;
            break;
        }
        headB = headB->next;
    }

    // Delete all items from hash table
    HASH_ITER(hh, hashTable, item, tmpItem) {
        HASH_DEL(hashTable, item);
        free(item);
    }

    return intersection;
}
