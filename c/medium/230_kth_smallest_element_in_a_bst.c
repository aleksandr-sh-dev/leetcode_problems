#include <stdio.h>
#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void inorder_traversal(struct TreeNode* root, int *k, int *result) {
    if (root == NULL) {
        return;
    }

    inorder_traversal(root->left, k, result);

    (*k)--;

    if ((*k) == 0 && (*result) == -1) {
        *result = root->val;
    }

    inorder_traversal(root->right, k, result);

    if ((*k) == 0 && (*result) == -1) {
        *result = root->val;
    }
} 

int kthSmallest(struct TreeNode* root, int k) {
    bool num_found = false;
    int result = -1;
    inorder_traversal(root, &k, &result);

    return result;
}
