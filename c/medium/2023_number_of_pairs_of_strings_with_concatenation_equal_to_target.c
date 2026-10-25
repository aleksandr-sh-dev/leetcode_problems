struct hashTable {
    char *key;
    int cnt;
    UT_hash_handle hh;
};

int numOfPairs(char** nums, int numsSize, char* target) {
    int pairs_counter = 0;
    int target_len = strlen(target);
    struct hashTable *hashTable = NULL;
    struct hashTable *item = NULL;
    struct hashTable *tmpItem = NULL;

    // Fill up the hash table
    for (int i = 0; i < numsSize; i++) {
        HASH_FIND_STR(hashTable, nums[i], item);
        if (item == NULL) {
            item = malloc(sizeof(struct hashTable));
            int cur_str_len = strlen(nums[i]);
            item->key = malloc(cur_str_len + 1); // +1 is null terminator
            memcpy(item->key, nums[i], cur_str_len + 1);
            item->cnt = 1;
            HASH_ADD_STR(hashTable, key, item);
        } 
        else {
            item->cnt++;
        }
    }

    // Iterate over nums again to find matching strings
    for (int i = 0; i < numsSize; i++) {
        int cur_str_len = strlen(nums[i]);

        // This string is too big, it's no use to check it
        if (cur_str_len > target_len) {
            continue;
        }

        // nums[i] string is not the copy of cur_str_len characters of target
        if (strncmp(nums[i], target, cur_str_len) != 0) {
            continue;
        }

        // Check if remaining string happens to be in the hash table
        int remain_str_len = target_len - cur_str_len;
        char *remain_str = malloc(sizeof(char) * (remain_str_len + 1));
        memcpy(remain_str, target + cur_str_len, (remain_str_len + 1));

        HASH_FIND_STR(hashTable, remain_str, item);
        if (item != NULL) {
            // If nums[i] equal to remain string that means we either checking the same index or there are multiple
            // nums[i] like strings
            if (strcmp(nums[i], remain_str) == 0)
                pairs_counter += item->cnt - 1;
            else
                pairs_counter += item->cnt;
        }
        free(remain_str);
    }

    HASH_ITER(hh, hashTable, item, tmpItem) {
        free(item->key);
        HASH_DEL(hashTable, item);
        free(item);
    }

    return pairs_counter;
}