#include "../../libs/uthash/src/uthash.h"

#define ENTRIES_NUM_DEFAULT (30)

struct Entry {
    int timestamp;
    char *value;
};

struct hashTable {
    struct Entry *entries;
    char* key;
    int entries_cnt;
    int entries_capacity;
    UT_hash_handle hh;
};

typedef struct {
    struct hashTable *hashTable;
} TimeMap;

TimeMap* timeMapCreate() {
    TimeMap *time_map = malloc(sizeof(TimeMap));
    time_map->hashTable = NULL;
    return time_map;
}

void timeMapSet(TimeMap* obj, char* key, char* value, int timestamp) {
    if (obj == NULL) {
        return;
    }

    if (key == NULL) {
        return;
    }

    int value_size = strlen(value) + 1;
    struct hashTable *item;

    HASH_FIND_STR(obj->hashTable, key, item);
    if (item == NULL) {
        item = malloc(sizeof(struct hashTable));
        int key_size = strlen(key) + 1;
        item->entries_cnt = 1;
        item->entries_capacity = ENTRIES_NUM_DEFAULT;

        // Copy key
        item->key = malloc(key_size);
        memcpy(item->key, key, key_size);

        // Create array of entries
        item->entries = malloc(sizeof(struct Entry) * item->entries_capacity);

        if (value != NULL) {
            item->entries[item->entries_cnt - 1].value = malloc(sizeof(char) * value_size);
            memcpy(item->entries[item->entries_cnt - 1].value, value, value_size);
        }
        item->entries[item->entries_cnt - 1].timestamp = timestamp;
        HASH_ADD_STR(obj->hashTable, key, item);
    } else {
        // Resize array if entries count is more than 50% of current size
        item->entries_cnt++;
        int current_entries_size = item->entries_capacity;
        if (item->entries_cnt >= (current_entries_size / 2)) {
            struct Entry *tmp = realloc(item->entries, sizeof(struct Entry) * current_entries_size * 2);
            if (tmp == NULL) {
                return;
            }
            item->entries = tmp;
            item->entries_capacity = current_entries_size * 2;
        }
        //////////////////////////////////////////////////////////////////////////

        item->entries[item->entries_cnt - 1].timestamp = timestamp;
        if (value != NULL) {
            item->entries[item->entries_cnt - 1].value = malloc(value_size);
            memcpy(item->entries[item->entries_cnt - 1].value, value, value_size);
        }
    }
}

char* timeMapGet(TimeMap* obj, char* key, int timestamp) {
    if (obj == NULL) {
        return "";
    }

    struct hashTable *item;

    HASH_FIND_STR(obj->hashTable, key, item);
    if (item == NULL) {
        return "";
    }

    int left = 0;
    int middle = 0;
    int right = item->entries_cnt;

    while (left < right) {
        middle = (left + right) / 2;
        if (item->entries[middle].timestamp == timestamp) {
            if (item->entries[middle].value != NULL) {
                return item->entries[middle].value;
            }
            return "";
        } else if (item->entries[middle].timestamp < timestamp) {
            left = middle + 1;
        } else {
            right = middle;
        }
    }

    int res_idx = (left == 0 ? left : left - 1);

    if (item->entries[res_idx].timestamp > timestamp) {
        return "";
    }

    if (item->entries[res_idx].value != NULL) {
        return item->entries[res_idx].value;
    }

    return "";
}

void timeMapFree(TimeMap* obj) {
    if (obj == NULL) {
        return;
    }
    struct hashTable *item, *tmpItem;
    HASH_ITER(hh, obj->hashTable, item, tmpItem) {
        HASH_DEL(obj->hashTable, item);
        free(item->key);
        for (int i = 0; i < item->entries_cnt; i++) {
            free(item->entries[i].value);
        }
        free(item->entries);
        free(item);
    }
    free(obj);
}
