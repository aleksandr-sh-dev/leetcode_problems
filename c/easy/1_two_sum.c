#include "../../libs/uthash/src/uthash.h"

#define SOLUTION_BRUTE_FORCE (1)
#define SOLUTION_HASH_TABLE  (2)

#define SOLUTION SOLUTION_HASH_TABLE

#if SOLUTION == SOLUTION_HASH_TABLE
// O(n) - time, O(n) - memory
struct hashTable {
    int key;
    int value;
    UT_hash_handle hh;
} *hashTable = NULL, *item, *tmpItem;

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    for (int i = 0; i < numsSize; i++) {
        // Finding item that has key = nums[i]
        HASH_FIND_INT(hashTable, &nums[i], item);
        if (item != NULL) {
            // Matching item was found, allocating memory for resulting array and return it
            int *res = malloc(sizeof(int) * 2);
            res[0] = item->value;
            res[1] = i;
            *returnSize = 2;

            // Iter allows us safely delete item and free it's memory from heap
            HASH_ITER(hh, hashTable, item, tmpItem) {
                HASH_DEL(hashTable, item);
                free(item);
            }
            return res;
        }
        // Fill up hash map if match was not found
        item = malloc(sizeof(struct hashTable));
        item->key = target - nums[i];
        item->value = i;
        HASH_ADD_INT(hashTable, key, item);
    }

    // No match was found, delete item and free it's memory from heap
    HASH_ITER(hh, hashTable, item, tmpItem) {
        HASH_DEL(hashTable, item);
        free(item);
    }

    // Return size is 0, returning valid pointer
    *returnSize = 0;
    return malloc(sizeof(int) * 0);
}
#endif // SOLUTION_HASH_TABLE

// O(n^2) - time, O(n) - memory
#if SOLUTION == SOLUTION_BRUTE_FORCE
int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    int *solution = (int *)malloc(2 * sizeof(int));
    *returnSize = 2;

    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[j] + nums[i] == target) {
                printf("\nSolution has been found ");
                solution[0] = i;
                solution[1] = j;
                return solution;
            }
        }
    }
    
    return 0;
}
#endif // SOLUTION_BRUTE_FORCE
