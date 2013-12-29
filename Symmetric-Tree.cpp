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
    bool isSymmetric(TreeNode *root) {
        //empty tree, return true
        if(NULL == root)
            return true;
        //travle two subtrees
        return work(root->left, root->right);
    }
    //@left :node in the left subtree of root
    //@riht :node in the right subtree of root
    //left and right are symmetric nodes!!!!
    bool work(TreeNode *left, TreeNode *right)
    {
        if(NULL == left && NULL == right)
            return true;
        if(NULL == left || NULL == right)
            return false;
        if(left->val != right->val)
            return false;
        //travel left's subtree and right's subtree
        bool ret = work(left->left, right->right);
        ret &= work(left->right, right->left);
        return ret;
    }
}; 
