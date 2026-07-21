#include <stdbool.h>
#include <stddef.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool check_if_symmetric(struct TreeNode *left, struct TreeNode *right) {
    if (left == NULL && right == NULL) {
        return true;
    } else if (left == NULL || right == NULL) { 
        return false;
    }

    if (left->val != right->val) {
        return false;
    }

    bool symmetric = check_if_symmetric(left->right, right->left);

    if (symmetric == false) {
        return false;
    }

    symmetric = check_if_symmetric(left->left, right->right);

    return symmetric;
}

bool isSymmetric(struct TreeNode* root) {
    if (root == NULL) {
        return true;
    }

    return check_if_symmetric(root->left, root->right);
}
