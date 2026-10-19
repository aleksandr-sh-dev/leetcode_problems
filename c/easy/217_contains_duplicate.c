#include <stdbool.h>
#include "../../libs/uthash/src/uthash.h"

#define SOLUTION_HASH_MAP 0
#define SOLUTION_SORTING 1

#define SOLUTION SOLUTION_SORTING

#if (SOLUTION == SOLUTION_HASH_MAP)
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
#elif (SOLUTION == SOLUTION_SORTING)
int comp(const void *a, const void *b) {
    int x = *(int *)a;
    int y = *(int *)b;

    if (x > y) {
        return 1;
    }

    if (x < y) {
        return -1;
    }

    return 0;
}

bool containsDuplicate(int* nums, int numsSize) {
    if (numsSize == 1) {
        return false;
    }

    if (numsSize == 2) {
        if (nums[0] == nums[1]) {
            return true;
        } else {
            return false;
        }
    }

    qsort(nums, numsSize, sizeof(int), comp);

    for (int i = 0; i < (numsSize - 1); i++) {
        if (nums[i] == nums[i + 1]) {
            return true;
        }
    }

    return false;
}
#endif // SOLUTION
