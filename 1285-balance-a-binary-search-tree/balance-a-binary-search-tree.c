/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* nodes[10000];
int count = 0;

void inorder(struct TreeNode* root) {
    if (root == NULL)
        return;

    inorder(root->left);

    nodes[count++] = root;

    inorder(root->right);
}

struct TreeNode* build(int left, int right) {
    if (left > right)
        return NULL;

    int mid = left + (right - left) / 2;

    struct TreeNode* root = nodes[mid];

    root->left = build(left, mid - 1);
    root->right = build(mid + 1, right);

    return root;
}

struct TreeNode* balanceBST(struct TreeNode* root) {
    count = 0;

    inorder(root);

    return build(0, count - 1);
}