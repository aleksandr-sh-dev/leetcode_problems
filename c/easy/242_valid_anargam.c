#include <stdbool.h>
#include "../../libs/uthash/src/uthash.h"

struct hashTable {
    int key;
    int count;
    UT_hash_handle hh;
};

bool isAnagram(char* s, char* t) {
    int s_len = strlen(s);
    int t_len = strlen(t);

    if (s_len != t_len) {
        return false;
    }

    struct hashTable *hashTableS = NULL;
    struct hashTable *hashTableT = NULL;
    struct hashTable *item = NULL;
    struct hashTable *tmpItem = NULL;

    // Fill up hash tables
    for (int i = 0; i < s_len; i++) {
        int key = (int)s[i];
        HASH_FIND_INT(hashTableS, &key, item);
        if (item == NULL) {
            item = malloc(sizeof(struct hashTable));
            item->key = key;
            item->count = 1;
            HASH_ADD_INT(hashTableS, key, item);
        } else {
            item->count++;
        }

        key = (int)t[i];
        HASH_FIND_INT(hashTableT, &key, item);
        if (item == NULL) {
            item = malloc(sizeof(struct hashTable));
            item->key = key;
            item->count = 1;
            HASH_ADD_INT(hashTableT, key, item);
        } else {
            item->count++;
        }
    }

    if (HASH_COUNT(hashTableS) != HASH_COUNT(hashTableT)) {
        struct hashTable *tmp, *tmp_itm;
        HASH_ITER(hh, hashTableS, tmp, tmp_itm) { 
            HASH_DEL(hashTableS, tmp); 
            free(tmp); 
        }
        HASH_ITER(hh, hashTableT, tmp, tmp_itm) { 
            HASH_DEL(hashTableT, tmp); 
            free(tmp);
        }
        return false;
    }

    bool is_anagram = true;
    struct hashTable *entry, *found;

    HASH_ITER(hh, hashTableS, entry, tmpItem) {
        HASH_FIND_INT(hashTableT, &entry->key, found);
        if (found == NULL || (entry->count != found->count)) {
            is_anagram = false;
            break;
        }
    }

    HASH_ITER(hh, hashTableS, item, tmpItem) {
        HASH_DEL(hashTableS, item);
        free(item);
    }

    HASH_ITER(hh, hashTableT, item, tmpItem) {
        HASH_DEL(hashTableT, item);
        free(item);
    }

    return is_anagram;
}
