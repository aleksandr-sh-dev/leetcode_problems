#include <stdio.h>
#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

void append_node(int **nodes, int *nodes_count, int val, int level) {
    int new_count = nodes_count[level] + 1;

    int *tmp = realloc(nodes[level], new_count * sizeof(int));
    if (tmp == NULL) {
        return;
    }

    nodes[level] = tmp;
    nodes[level][nodes_count[level]] = val;
    nodes_count[level] = new_count;
}

void preorder_traversal(struct TreeNode *root, int ***arrays, int **nodes_count, int *capacity, int *level_num, int level) {
    if (root == NULL) {
        return;
    }

    if (level == (*capacity)) {
        int old_capacity = *capacity;
        (*capacity) *= 2;
        int new_capacity = *capacity;
        int **tmp = realloc(*arrays, (*capacity) * sizeof(int *));
        *arrays = tmp;
        
        memset(*arrays + old_capacity, 0, (new_capacity - old_capacity) * sizeof(int *));

        int *tmp_nodes = realloc(*nodes_count, (*capacity) * sizeof(int));
        *nodes_count = tmp_nodes;

        memset(*nodes_count + old_capacity, 0, (new_capacity - old_capacity) * sizeof(int));
    }

    if (level >= *level_num) {
        (*level_num)++;
    }

    append_node(*arrays, *nodes_count, root->val, level);

    preorder_traversal(root->left, arrays, nodes_count, capacity, level_num, level + 1);
    preorder_traversal(root->right, arrays, nodes_count, capacity, level_num, level + 1);
}

int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    int capacity = 10;
    int current_level = 0;
    int level_num = 0;
    int *nodes_count = calloc(capacity, sizeof(int));
    int **arrays = calloc(capacity, sizeof(int *));

    preorder_traversal(root, &arrays, &nodes_count, &capacity, &level_num, 0);

    int *ret_col_size = malloc(sizeof(int) * level_num);
    for (int i = 0; i < level_num; i++) {
        ret_col_size[i] = nodes_count[i];
    }

    *returnSize = level_num;
    *returnColumnSizes = ret_col_size;

    free(nodes_count);

    return arrays;
}
