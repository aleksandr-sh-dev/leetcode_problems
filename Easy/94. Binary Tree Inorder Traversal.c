static void inorder_traversal(struct TreeNode *root, int *traversal, int *size);

void inorder_traversal(struct TreeNode *root, int *traversal, int *size)
{
    if (root == NULL) return;

    inorder_traversal(root->left, traversal, size);
    traversal[(*size)++] = root->val;
    inorder_traversal(root->right, traversal, size);
}

int *inorderTraversal(struct TreeNode *root, int *returnSize)
{
    *returnSize = 0;
    int *traversal = (int*)malloc(100 * sizeof(int));

    inorder_traversal(root, traversal, returnSize);

    return traversal;
}
