bool isSameTree(struct TreeNode *p, struct TreeNode *q)
{
    if ((p == NULL) && (q == NULL)) {
        return true;
    }

    if ((p == NULL) && (q != NULL)) {
        return false;
    }

    if ((p != NULL) && (q == NULL)) {
        return false;
    }

    if (p->val != q->val) {
        return false;
    }

    if ((p->left != NULL) || (q->left != NULL)) {
        if (!isSameTree(p->left, q->left)) {
            return false;
        }
    }

    if ((p->right != NULL) || (q->right != NULL)) {
        if (!isSameTree(p->right, q->right)) {
            return false;
        }
    }

    return true;
}
