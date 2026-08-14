#include "../../libs/uthash/src/uthash.h"

struct Node {
    int val;
    struct Node *next;
    struct Node *random;
};

struct hashTable {
    struct Node *key;
    struct Node *copy;
    UT_hash_handle hh;
};

struct Node* copyRandomList(struct Node* head) {
    if (head == NULL) {
        return NULL;
    }

    struct hashTable *hashTable = NULL;
    struct hashTable *item, *randItem, *nextItem, *tmpItem;

    struct Node *curr = head;
    struct Node *copy = NULL;
    struct Node *prev_copy = NULL;

    // Fill Up hash table with original node and copy node;
    while (curr != NULL) {
        HASH_FIND_PTR(hashTable, &curr, item);
        if (item == NULL) {
            item = malloc(sizeof(struct hashTable));
            copy = malloc(sizeof(struct Node));

            copy->val = curr->val;
            item->copy = copy;
            item->key = curr;
            HASH_ADD_PTR(hashTable, key, item);
        }
        curr = curr->next;
    }

    while (head != NULL) {
        HASH_FIND_PTR(hashTable, &head, item);
        HASH_FIND_PTR(hashTable, &head->next, nextItem);
        HASH_FIND_PTR(hashTable, &head->random, randItem);

        if (randItem != NULL) {
            item->copy->random = randItem->copy;
        } else {
            item->copy->random = NULL;
        }

        if (nextItem != NULL) {
            item->copy->next = nextItem->copy;
        } else {
            item->copy->next = NULL;
        }
        
        head = head->next;
    }

    struct Node *res = NULL;

    HASH_ITER(hh, hashTable, item, tmpItem) {
        if (res == NULL) {
            res = item->copy;
        }
        free(item);
    }

    return res;
}
