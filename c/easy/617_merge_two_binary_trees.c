#include <stdio.h>
#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void merge(struct TreeNode* root1, struct TreeNode* root2, struct TreeNode** new) {
    if (root1 == NULL && root2 == NULL) {
        *new = NULL;
        return;
    }

    *new = malloc(sizeof(struct TreeNode));

    if (root1 == NULL) {
        (*new)->val = root2->val;
        merge(NULL, root2->left, &(*new)->left);
        merge(NULL, root2->right, &(*new)->right);
    } else if (root2 == NULL) {
        (*new)->val = root1->val;
        merge(root1->left, NULL, &(*new)->left);
        merge(root1->right, NULL, &(*new)->right);
    } else {
        (*new)->val = root1->val + root2->val;
        merge(root1->left, root2->left, &(*new)->left);
        merge(root1->right, root2->right, &(*new)->right);
    }
}

struct TreeNode* mergeTrees(struct TreeNode* root1, struct TreeNode* root2) {
    if (root1 == NULL) {
        return root2;
    }

    if (root2 == NULL) {
        return root1;
    }

    if (root1 == NULL && root2 == NULL) {
        return NULL;
    }

    struct TreeNode* new_root = NULL;

    merge(root1, root2, &new_root);

    return new_root;
}
