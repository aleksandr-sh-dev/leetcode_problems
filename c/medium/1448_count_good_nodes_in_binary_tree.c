#include <stdio.h>
#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void calculate_good_nodes(struct TreeNode* root, int *good_nodes, int max) {
    if (root == NULL) {
        return;
    }

    if (root->val >= max) {
        printf("Good node: %d\n",root->val);
        (*good_nodes)++;
        max = root->val;
    }

    calculate_good_nodes(root->left, good_nodes, max);
    calculate_good_nodes(root->right, good_nodes, max);
}

int goodNodes(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }

    int min_value = -10001;
    int good_nodes = 0;

    calculate_good_nodes(root, &good_nodes, min_value);

    return good_nodes;
}
