#include <stdbool.h>
#include "../../libs/uthash/src/uthash.h"

struct hashTable {
    char *key;
    int index;
    int anagram_num;
    UT_hash_handle hh;
};

char*** groupAnagrams(char** strs, int strsSize, int* returnSize, int** returnColumnSizes) {
    if (strs == NULL) {
        return NULL;
    }

    struct hashTable *hashTable = NULL, *item;

    int curr_anagrams_idx = 0;
    char key[105] = {0};

    int *group_word_count = calloc(strsSize, sizeof(int));

    for (int i = 0; i < strsSize; i++) {
        int letters[26] = {0};
        int len = strlen(strs[i]);
        for (int j = 0; j < len; j++) {
            letters[strs[i][j] - 'a']++;
        }

        char temp[5];
        memset(key, 0, sizeof(key));
        for (int k = 0; k < 26; k++) {
            sprintf(temp, "%d#", letters[k]);
            strcat(key, temp);
        }

        HASH_FIND_STR(hashTable, key, item);
        if (item == NULL) {
            item = malloc(sizeof(struct hashTable));
            item->key = malloc(sizeof(key));
            memcpy(item->key, key, sizeof(key));
            item->index = curr_anagrams_idx;
            item->anagram_num = 0;
            group_word_count[item->index] = 1;
            HASH_ADD_STR(hashTable, key, item);
            curr_anagrams_idx++;
        } else {
            group_word_count[item->index]++;
        }
    }

    char ***result = malloc(curr_anagrams_idx * sizeof(char**));

    for (int g = 0; g < curr_anagrams_idx; g++) {
        result[g] = malloc(group_word_count[g] * sizeof(char*));
    }

    *returnSize = curr_anagrams_idx;
    *returnColumnSizes = group_word_count;

    for (item = hashTable; item != NULL; item = item->hh.next) {
        item->anagram_num = 0;
    }

    for (int i = 0; i < strsSize; i++) {
        int letters[26] = {0};
        int len = strlen(strs[i]);
        for (int j = 0; j < len; j++) {
            letters[strs[i][j] - 'a']++;
        }

        char temp[5];
        memset(key, 0, sizeof(key));
        for (int k = 0; k < 26; k++) {
            sprintf(temp, "%d#", letters[k]);
            strcat(key, temp);
        }

        HASH_FIND_STR(hashTable, key, item);

        result[item->index][item->anagram_num] = malloc(len + 1);
        memcpy(result[item->index][item->anagram_num], strs[i], len);
        result[item->index][item->anagram_num][len] = '\0';
        item->anagram_num++;
    }

    return result;
}
