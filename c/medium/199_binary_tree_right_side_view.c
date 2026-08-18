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
void traversal(struct TreeNode *root, int **nums, bool *level_acquired, int *level_num, int level) {
    if (root == NULL) {
        return;
    }

    if (level >= *level_num) {
        (*level_num)++;
    }

    if (level_acquired[level] == false) {
        (*nums)[level] = root->val;
        level_acquired[level] = true;
    }

    traversal(root->right, nums, level_acquired, level_num, level + 1);
    traversal(root->left, nums, level_acquired, level_num, level + 1);
}

int* rightSideView(struct TreeNode* root, int* returnSize) {
    int *result = calloc(100, sizeof(int));
    bool *level_acquired = calloc(100, sizeof(bool));
    int level_num = 0;

    traversal(root, &result, level_acquired, &level_num, 0);

    *returnSize = level_num;
    free(level_acquired);

    return result;
}
