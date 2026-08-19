#include <stdio.h>
#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool check_if_bst(struct TreeNode* root, long min, long max) {
    if (root == NULL) {
        return true;
    }

    if (root->val <= min) {
        return false;
    }

    if (root->val >= max) {
        return false;
    }
    
    if (!check_if_bst(root->left, min, root->val)) {
        return false;
    }

    if (!check_if_bst(root->right, root->val, max)) {
        return false;
    }

    return true;
}

bool isValidBST(struct TreeNode* root) {
    if (root == NULL) {
        return false;
    }

    if (root->left == NULL && root->right == NULL) {
        return true;
    }

    if (!check_if_bst(root, -2147483649, 2147483649)) {
        return false;
    }

    return true;
}
