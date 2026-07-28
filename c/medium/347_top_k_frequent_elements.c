#include "../../libs/uthash/src/uthash.h"

struct hashTable {
    int key;
    int counter;
    UT_hash_handle hh;
};

int compare_by_counter(const struct hashTable *a, const struct hashTable *b) {
    return (b->counter - a->counter); 
}

int* topKFrequent(int* nums, int numsSize, int k, int* returnSize) {
    if (nums == NULL) {
        return NULL;
    }

    int *result = malloc(sizeof(int) * k);

    if (numsSize == 1) {
        *returnSize = 1;
        result[0] = nums[0];
        return result;
    }

    struct hashTable *hashTable = NULL, *item, *tmpItem;

    for (int i = 0; i < numsSize; i++) {
        HASH_FIND_INT(hashTable, &nums[i], item);
        if (item == NULL) {
            item = malloc(sizeof(struct hashTable));
            item->key = nums[i];
            item->counter = 1;
            HASH_ADD_INT(hashTable, key, item);
        } else {
            item->counter++;
        }
    }

    // Sort in descending order by counter
    HASH_SORT(hashTable, compare_by_counter);

    int counter = 0;

    HASH_ITER(hh, hashTable, item, tmpItem) {
        result[counter] = item->key;
        HASH_DEL(hashTable, item);
        free(item);
        counter++;
        if (counter >= k) {
            break;
        }
    }

    *returnSize = counter;

    return result;
}
