#include <stdbool.h>
#include <stddef.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int is_subtree_balanced(struct TreeNode *root, int cur_depth) {
    if (root == NULL) {
        return cur_depth;
    }

    cur_depth++;
    int left_height = is_subtree_balanced(root->left, cur_depth);
    int right_height = is_subtree_balanced(root->right, cur_depth);

    int height_diff = abs(left_height - right_height);

    if (height_diff > 1) {
        return -1;
    }

    return (left_height > right_height ? left_height : right_height);
}

bool isBalanced(struct TreeNode* root) {
    if (root == NULL) {
        return true;
    }

    int cur_depth = 0;

    int left_depth = is_subtree_balanced(root->left, cur_depth);

    if (left_depth == -1) {
        return false;
    }

    int right_depth = is_subtree_balanced(root->right, cur_depth);

    if (right_depth == -1) {
        return false;
    }

    int diff = abs(left_depth - right_depth);

    if (diff > 1) {
        return false;
    }

    return true;
}
