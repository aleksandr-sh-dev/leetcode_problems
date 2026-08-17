#include <stdio.h>
#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define ARROW "->"

char* append_str(char *str1, char *str2) {
    if (str1 == NULL) {
        return str2;
    }

    if (str2 == NULL) {
        return str1;
    }

    char *new_str = malloc(strlen(str1) + strlen(str2) + 1);
    new_str[0] = '\0';
    strcat(new_str, str1);
    strcat(new_str, str2);

    return new_str;
}

char* append_int(char *str1, int num) {
    char number_str[5];
    snprintf(number_str, sizeof(number_str), "%d", num);

    return append_str(str1, number_str);
}

void get_tree_path(struct TreeNode* root, char ***path, char *current_path, int *capacity, int *curr_str_num) {
    if (root == NULL) {
        return;
    }

    char *tmp = append_int(current_path, root->val);
    free(current_path);
    current_path = tmp;

    if (root->left == NULL && root->right == NULL) {
        (*path)[*curr_str_num] = malloc(strlen(current_path) + 1);
        strcpy((*path)[*curr_str_num], current_path);
        (*curr_str_num)++;
        // Reallocate memory for more strings
        if (*curr_str_num == *capacity) {
            *capacity = (*capacity) * 2;
            char **tmp = realloc(*path, *capacity * sizeof(char *));
            *path = tmp;
        }
    } else {
        char *tmp = append_str(current_path, ARROW);
        free(current_path);
        current_path = tmp;
    }

    char *left_path = malloc(strlen(current_path) + 1);
    strcpy(left_path, current_path);

    char *right_path = malloc(strlen(current_path) + 1);
    strcpy(right_path, current_path);

    get_tree_path(root->left, path, left_path, capacity, curr_str_num);
    get_tree_path(root->right, path, right_path, capacity, curr_str_num);
}

char** binaryTreePaths(struct TreeNode* root, int* returnSize) {
    int capacity = 14;
    int str_num = 0;
    char *current_path = malloc(sizeof(char));
    current_path[0] = '\0';
    char **path = malloc(sizeof(char *) * capacity);

    if (root->left == NULL && root->right == NULL) {
        *returnSize = 1;
        path[0] = malloc(1);
        path[0][0] = '\0';
        path[0] = append_int(path[0], root->val);
        return path;
    }

    get_tree_path(root, &path, current_path, &capacity, &str_num);

    *returnSize = str_num;

    return path;
}
