/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode *root) {
        int ret = 1;    //the node itself
        if(NULL == root)    //if root is a empty tree then return 0
            return 0;
        if(NULL != root->left) //if root has left subtree
            ret = max(ret, 1+maxDepth(root->left));
        if(NULL != root->right) //if root has right subtree
            ret = max(ret, 1+maxDepth(root->right));
        return ret;
    }
};