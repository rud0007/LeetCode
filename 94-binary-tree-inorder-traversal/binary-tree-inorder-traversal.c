/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void inorder(struct TreeNode* root, int* index,int *arr){
    if(root==NULL){
        return;
    }
    inorder(root->left,index,arr);
    arr[(*index)++]=root->val;
     inorder(root->right,index,arr); 
}
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int* arr = (int*)malloc(100 * sizeof(int));
    int index=0;

    inorder(root,&index,arr);

    *returnSize=index;

    return arr;
}