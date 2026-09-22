/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int sumhelper(struct TreeNode* root,int num){
    if(root==NULL){
        return 0;
    }
    num=num*10+root->val;
    if(root->left==NULL && root->right==NULL){
        return num;
    }
    return sumhelper(root->left,num)+sumhelper(root->right,num);
}
int sumNumbers(struct TreeNode* root) {
    return sumhelper(root,0);
}