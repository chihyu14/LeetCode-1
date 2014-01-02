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
    bool isBalanced(TreeNode *root) {
        //empty tree
        if(NULL == root)
            return true;
        //@ret: answer
        bool ret = true;
        travel(root, ret);
        return ret;
    }
    //@root: current node
    //@ret:  refrence of the answer
    int travel(TreeNode *root, bool &ret)
    {
        //leaf node
        if((NULL==root->left) && (NULL==root->right))
            return 1;
        int l,r;
        //height of left subtree
        if(NULL != root->left)
            {
                l = travel(root->left, ret);
            }
        else
            {
                l = 0;
            }
        //height of right subtree
        if(NULL != root->right)
            {
                r = travel(root->right, ret);
            }
        else
            {
                r = 0;
            }
        //differences of two subtrees are bigger than 1
        if(abs(l-r)>1)
            ret = false;
        //return the max height
        return max(l,r)+1;
    }
};