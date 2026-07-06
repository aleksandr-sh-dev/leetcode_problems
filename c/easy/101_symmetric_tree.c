/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool traversal(struct TreeNode* left, struct TreeNode* right)
{
    if ((left == NULL) && (right == NULL)) {
        return true;
    }

    if ((left == NULL) && (right != NULL)) {
        return false;
    }

    if ((left != NULL) && (right == NULL)) {
        return false;
    }

    if (left->val == right->val) {
        if (!traversal(left->left, right->right)) {
            return false;
        }
        if (!traversal(left->right, right->left)) {
            return false;
        }
    }
    else {
        return false;
    }

    return true;
}

bool isSymmetric(struct TreeNode* root)
{
    if (root == NULL) {
        return true;
    }
    
    if (!traversal(root->left, root->right)) {
        return false;
    }

    return true;
}
