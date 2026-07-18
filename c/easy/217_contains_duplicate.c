#include <stdbool.h>
#include "../../libs/uthash/src/uthash.h"

bool containsDuplicate(int* nums, int numsSize) {
    struct hashTable {
        int key;
        UT_hash_handle hh;
    } *hashTable = NULL, *item, *tmpItem;

    bool contains_duplicate = false;

    for (int i = 0; i < numsSize; i++) {
        HASH_FIND_INT(hashTable, &nums[i], item);
        if (item == NULL) {
            item = malloc(sizeof(struct hashTable));
            item->key = nums[i];
            HASH_ADD_INT(hashTable, key, item);
        } else { 
            contains_duplicate = true;
            break;
        }
    }

    HASH_ITER(hh, hashTable, item, tmpItem) {
        HASH_DEL(hashTable, item);
        free(item);
    }

    return contains_duplicate;
}
