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
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if(NULL == p && NULL == q)  //p and q are all empty trees
            return true;
        if(NULL == p)   //p is empty tree and q isn't
            return false;
        if(NULL == q)   //q is empty tree and p isn't
            return false;
        
        if((p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right))  
            //if p->val == q->val and their subtrees are equal
            return true;
        return false;
    }
};