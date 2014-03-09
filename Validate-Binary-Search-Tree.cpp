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
    bool isValidBST(TreeNode *root) {
        //empty tree
        if(NULL == root)
            return true;
        //only one node
        if(NULL == root->left && NULL == root->right)
            return true;
        //@ret: we will return
        //first test subtree
        bool ret = isValidBST(root->left) && isValidBST(root->right);
        if(ret)//if two subtrees are validBST
        {
            int l, r;
            TreeNode *t;
            t = root->left;
            if(NULL != t)//root has left subtree
            {
                while(NULL != t)
                    {
                        l = t->val;
                        t = t->right;
                    }
                if(l>=root->val)//some nodes' val are bigger than root->val
                    ret = false;
            }
            
            t = root->right;
            if(NULL != t)//root has right subtree
            {
                while(NULL != t)
                    {
                        r = t->val;
                        t = t->left;
                    }
                if(r<=root->val) //same as above
                    ret = false;
            }
            
        }
        return ret;
    }
};