/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#define ARRAY_TO_BST_MIDDLE    (2u)

struct TreeNode* newNode(int data);

struct TreeNode* newNode(int data)
{
  struct TreeNode* node = malloc(sizeof(struct TreeNode));
  node->val = data;
  node->left = NULL;
  node->right = NULL;

  return node;
}

struct TreeNode* sortedArrayToBST(int* nums, int numsSize)
{
  if (numsSize == 0) {
    return NULL;
  }

  int middle_element = (numsSize / ARRAY_TO_BST_MIDDLE);

  struct TreeNode* root = newNode(nums[middle_element]);

  root->left = sortedArrayToBST(nums, middle_element);
  root->right = sortedArrayToBST(nums + middle_element + 1, numsSize - middle_element - 1);

  return root;
}
