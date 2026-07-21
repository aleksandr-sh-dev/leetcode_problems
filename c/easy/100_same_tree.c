struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

#include <stdbool.h>
#include <stddef.h>

bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    if (p == NULL && q == NULL) {
        return true;
    } else if (p == NULL || q == NULL) {
        return false;
    }

    if (p->val != q->val) {
        return false;
    }

    bool same = isSameTree(p->left, q->left);

    if (same == false) {
        return same;
    }

    same = isSameTree(p->right, q->right);

    return same;
}
