#include <stdio.h>
#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool is_the_same(struct TreeNode *root, struct TreeNode *subRoot) {
    if (root == NULL && subRoot == NULL) {
        return true;
    } else if (root == NULL && subRoot != NULL) {
        return false;
    } else if (root != NULL && subRoot == NULL) {
        return false;
    }

    if (root->val == subRoot->val) {
        bool left_same = is_the_same(root->left, subRoot->left);
        bool right_same = is_the_same(root->right, subRoot->right);

        return (left_same && right_same);
    }

    return false;
}

bool isSubtree(struct TreeNode* root, struct TreeNode* subRoot) {
    if (root == NULL && subRoot == NULL) {
        return true;
    } else if (root == NULL && subRoot != NULL) {
        return false;
    } else if (root != NULL && subRoot == NULL) {
        return false;
    }

    // Found root value equeal subRoot value, start check if subtrees are the same
    if (root->val == subRoot->val) {
        bool the_same = is_the_same(root, subRoot);
        if (the_same) {
            return true;
        }
    }

    bool the_same = isSubtree(root->left, subRoot);
    if (the_same) {
        return true;
    }

    the_same = isSubtree(root->right, subRoot);

    return the_same;
}
