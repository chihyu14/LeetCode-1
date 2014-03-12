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
    //first flatten the tree, and set all subtree be left
public:
    void flatten(TreeNode *root) {
        //empty tree
        if(NULL == root)
            return;
        //@before: auxiliray value
        TreeNode *before = root;
        before = work(before, root->left);
        work(before, root->right);
        //change left subtree to right subtree
        before = root;
        TreeNode *t;
        while(NULL != before)
        {
            before->right = before->left;
            t = before->left;
            before->left = NULL;
            before = t;
        }
    }
    //@before: root's last node, we will set before->left = root
    TreeNode* work(TreeNode *before, TreeNode *root)
    {
        //empty tree
        if(NULL == root)
            return before;
        before->left = root;
        //update before
        before = root;
        //set all nodes in left subtree 
        before = work(before, root->left);
        //set all nodes in right subteee
        before = work(before, root->right);
        //return before
        return before;
    }
};