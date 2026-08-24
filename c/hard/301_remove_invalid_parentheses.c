/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include "../../libs/uthash/src/uthash.h"
#include <stdbool.h>

struct Node {
    char *str;
    int level;
};

struct Queue {
    struct Node **data;
    int front;
    int rear;
    int capacity;
};

struct HashTable {
    char *key;
    UT_hash_handle hh;
};

struct Queue* createQueue(int capacity) {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->data = (struct Node **)malloc(capacity * sizeof(struct Node *));
    q->front = 0;
    q->rear = 0;
    q->capacity = capacity;
    return q;
}

bool isEmpty(struct Queue* q) {
    return q->front == q->rear;
}

void enqueue(struct Queue* q, struct Node *val) {
    q->data[q->rear++] = val;
}

struct Node* dequeue(struct Queue* q) {
    return q->data[q->front++];
}

struct Node* peek(struct Queue* q) {
    return q->data[q->front];
}

bool check_if_str_valid(char *s, int s_len) {
    int num_open_parentheses = 0;
    int num_close_parentheses = 0;

    for (int i = 0; i < s_len; i++) {
        if (s[i] == '(') {
            num_open_parentheses++;
        } else if (s[i] == ')') {
            num_close_parentheses++;
        }

        if (num_close_parentheses > num_open_parentheses) {
            return false;
        }
    }

    if (num_close_parentheses == 0 && num_open_parentheses == 0) {
        return true;
    }

    if (num_close_parentheses != num_open_parentheses) {
        return false;
    }

    return true;
}

void mark_visited(struct HashTable **visited, char *str) {
    struct HashTable *item;

    HASH_FIND_STR(*visited, str, item);

    if (item == NULL) {
        item = malloc(sizeof(struct HashTable));
        item->key = str;

        HASH_ADD_KEYPTR(
            hh,
            *visited,
            item->key,
            strlen(item->key),
            item
        );
    }
}

bool is_visited(struct HashTable **visited, char *str) {
    struct HashTable *item;
    HASH_FIND_STR(*visited, str, item);
    return (item != NULL);
}

char* remove_element_from_str(char *s, int s_len, int del_idx) {
    char *new_str = malloc(sizeof(char) * s_len);

    int first_str_part = del_idx;
    int second_str_part = s_len - del_idx - 1;
    
    memcpy(new_str, s, first_str_part);
    memcpy(new_str + first_str_part, s + del_idx + 1, second_str_part);

    new_str[s_len - 1] = '\0';

    return new_str;
}

char** removeInvalidParentheses(char* s, int* returnSize) {
    int s_len = strlen(s);
    int valid_strs = 0;
    int current_level = 0;
    int capacity = 100000;

    bool found_correct_str = false;
    struct Queue *q = createQueue(capacity);
    char **res = malloc(sizeof(char *) * capacity);

    struct Node *head = malloc(sizeof(struct Node));
    head->str = malloc(sizeof(char) * (s_len + 1));
    memcpy(head->str, s, (s_len + 1));
    head->level = 0;

    struct HashTable *visited = NULL; 
    mark_visited(&visited, head->str);

    enqueue(q, head);
    
    while(!(isEmpty(q))) {
        char prev_symbol = 'A';

        struct Node *node = dequeue(q);

        int cur_str_len = strlen(node->str);

        if (found_correct_str && node->level > current_level) {
            continue;
        }

        current_level = node->level;
        
        if (check_if_str_valid(node->str, cur_str_len)) {
            found_correct_str = true;
            res[valid_strs] = malloc(sizeof(char) * (cur_str_len + 1));
            memcpy(res[valid_strs], node->str, cur_str_len + 1);
            valid_strs++;
        }

        if (!found_correct_str) {
            for (int i = 0; i < cur_str_len; i++) {
                if (i > 0 && node->str[i] == node->str[i - 1]) { 
                    continue;
                }

                if (node->str[i] != '(' && node->str[i] != ')') {
                    continue;
                }

                prev_symbol = node->str[i];

                struct Node *new_node = malloc(sizeof(struct Node));
                new_node->str = remove_element_from_str(node->str, cur_str_len, i);
                new_node->level = node->level + 1;

                if (!is_visited(&visited, new_node->str)) {
                    mark_visited(&visited, new_node->str);
                    enqueue(q, new_node);
                } else {
                    free(new_node->str);
                    free(new_node);
                }
            }
        }
    }

    *returnSize = valid_strs;

    return res;
}
