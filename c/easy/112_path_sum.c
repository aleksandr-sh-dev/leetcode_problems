#include <stdio.h>
#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool has_path_sum(struct TreeNode* root, int current_sum, int target) {
    if (root == NULL) {
        return false;
    }

    current_sum += root->val;

    if (root->left == NULL && root->right == NULL && current_sum == target) {
        return true;
    }

    if (has_path_sum(root->left, current_sum, target)) {
        return true;
    }

    if (has_path_sum(root->right, current_sum, target)) {
        return true;
    }

    return false;
}

bool hasPathSum(struct TreeNode* root, int targetSum) {
    if (root == NULL) {
        return 0;
    }

    if (root->left != NULL)
        if (has_path_sum(root->left, root->val, targetSum)) {
            return true;
        }
    
    if (root->right != NULL)
        if (has_path_sum(root->right, root->val, targetSum)) {
            return true;
        }

    if (root->right == NULL && root->left == NULL) {
        if (root->val == targetSum) {
            return true;
        }
    }

    return false;
}
