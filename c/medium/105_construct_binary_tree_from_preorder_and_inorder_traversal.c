#include <stdio.h>
#include "../../libs/uthash/src/uthash.h"

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


struct hashTable {
    int key;
    int idx;
    UT_hash_handle hh;
} *hashTable = NULL, *item, *tmpItem;

struct TreeNode* create_tree(struct TreeNode *root, int** preorder, int** inorder, int inorderSize, int *cur_preorder_idx, int left, int right) {
    if (left > right) {
        return NULL;
    }

    int curr_root = (*preorder)[*cur_preorder_idx];
    int split_idx = 0;

    root = malloc(sizeof(struct TreeNode));
    root->val = curr_root;
    root->left = NULL;
    root->right = NULL;

    HASH_FIND_INT(hashTable, &curr_root, item);
    split_idx = item->idx;

    (*cur_preorder_idx)++;
    root->left = create_tree(root->left, preorder, inorder, inorderSize, cur_preorder_idx, left, split_idx - 1);
    root->right = create_tree(root->right, preorder, inorder, inorderSize, cur_preorder_idx, split_idx + 1, right);

    return root;
}

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
    if (preorderSize == 1) {
        struct TreeNode *root = malloc(sizeof(struct TreeNode));
        root->val = preorder[0];
        root->left = NULL;
        root->right = NULL;
        return root;
    }

    // Create hash table;
    for (int i = 0; i < inorderSize; i++) {
        HASH_FIND_INT(hashTable, &inorder[i], item);
        item = malloc(sizeof(struct hashTable));
        item->key = inorder[i];
        item->idx = i;
        HASH_ADD_INT(hashTable, key, item);
    }

    int cur_preorder_idx = 0;
    struct TreeNode *root = create_tree(root, &preorder, &inorder, inorderSize, &cur_preorder_idx, 0, (preorderSize - 1));

    HASH_ITER(hh, hashTable, item, tmpItem) {
        HASH_DEL(hashTable, item);
        free(item);
    }

    return root;
}
