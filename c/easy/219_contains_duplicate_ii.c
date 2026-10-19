#include <stdbool.h>
#include "../../libs/uthash/src/uthash.h"

struct hashTable {
    int key;
    UT_hash_handle hh;
};

bool containsNearbyDuplicate(int* nums, int numsSize, int k) {
    // No duplicates
    if (numsSize == 1) {
        return false;
    }

    // Check if window size is big enough and check for duplicates
    if (numsSize == 2) {
        if (k > 0) {
            if (nums[0] == nums[1]) {
                return true;
            } else {
                return false;
            }
        }
    }

    // Always no duplicates
    if (k == 0) {
        return false;
    }

    struct hashTable *hashTable = NULL;
    struct hashTable *item = NULL;
    struct hashTable *tmpItem = NULL;
    bool found_duplicate = false;

    // Fill the first window into hash map
    for (int i = 0; i <= k; i++) {
        if (i == numsSize) {
            break;
        }

        int num = (int)nums[i];
        HASH_FIND_INT(hashTable, &num, item);
        if (item == NULL) {
            item = malloc(sizeof(struct hashTable));
            item->key = num;
            HASH_ADD_INT(hashTable, key, item);
        } else {
            // Found duplicate
            found_duplicate = true;
            break;
        }
    }

    int i = 1;
    int j = k + 1;

    while ((!found_duplicate) && (j < numsSize)) {
        // Delete the oldest element first
        struct hashTable *oldest = hashTable;
        HASH_DEL(hashTable, oldest);
        free(oldest);

        int num = (int)nums[j];
        HASH_FIND_INT(hashTable, &num, item);
        if (item == NULL) {
            item = malloc(sizeof(struct hashTable));
            item->key = num;
            HASH_ADD_INT(hashTable, key, item);
        } else {
            found_duplicate = true;
        }

        j++;
        i++;
    }

    // Clear hash table
    HASH_ITER(hh, hashTable, item, tmpItem) {
        HASH_DEL(hashTable, item);
        free(item);
    }

    return found_duplicate;
}