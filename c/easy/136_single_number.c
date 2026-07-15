#include <stddef.h>

#define SOLUTION_XOR        (1) // O(1) space, O(n) time
#define SOLUTION_HASH_TABLE (2) // O(n) space, O(n) time 

#define SOLUTION SOLUTION_XOR

#if SOLUTION == SOLUTION_XOR
int singleNumber(int* nums, int numsSize) {
    if (nums == NULL) {
        return 0;
    }

    if (numsSize == 1) {
        return nums[0];
    }
    
    int answer = 0;

    for(int i = 0; i < numsSize; i++) {
        answer ^= nums[i];
    }

    return answer;
}
#endif // SOLUTION_XOR

#if SOLUTION == SOLUTION_HASH_TABLE
#include "../../libs/uthash/src/uthash.h"

struct hashTable {
    int key;
    UT_hash_handle hh;
} *hashTable = NULL, *item, *tmpItem;

int singleNumber(int* nums, int numsSize) {
    if (nums == NULL) {
        return 0;
    }

    if (numsSize == 1) {
        return nums[0];
    }
    
    int answer = 0;

    for(int i = 0; i < numsSize; i++) {
        HASH_FIND_INT(hashTable, &nums[i], item);
        if (item != NULL) {
            HASH_DEL(hashTable, item);
            free(item);
        } else {
            item = malloc(sizeof(struct hashTable));
            item->key = nums[i];
            HASH_ADD_INT(hashTable, key, item);
        }
    }

    if (hashTable != NULL) {
        answer = hashTable->key;
    }

    HASH_ITER(hh, hashTable, item, tmpItem) {
        HASH_DEL(hashTable, item);
        free(item);
    }

    return answer;
}
#endif // SOLUTION_HASH_TABLE
