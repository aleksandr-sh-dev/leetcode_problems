#include <stdio.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int get_diam_of_tree(struct TreeNode* root, int *diameter) {
    if (root == NULL) {
        return 0;
    }

    int left_depth = get_diam_of_tree(root->left, diameter);
    int right_depth = get_diam_of_tree(root->right, diameter);

    int curr_diam = left_depth + right_depth;

    if (curr_diam > *diameter) {
        *diameter = curr_diam;
    }

    return 1 + (left_depth > right_depth ? left_depth : right_depth);
}

int diameterOfBinaryTree(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }

    int diam = 0;
    get_diam_of_tree(root, &diam);
    return diam;
}
