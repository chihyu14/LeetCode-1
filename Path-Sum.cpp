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
    bool hasPathSum(TreeNode *root, int sum) {
        //if root is an empty tree
        if(NULL == root)
            return false;
        //travel the tree
        return work(root, sum, 0);
    }
    //@root: the current node
    //@sum: the given sum
    //@now: the sum from root to the node's parent
    bool work(TreeNode *root, int sum, int now)
        {
            //add root->val to now
            now += root->val;
            //if root is a leaf node
            if(NULL == root->left && NULL == root->right)
                {
                    if(now == sum)//true
                        return true;
                    return false;//false
                }
            //@ret: the return valuable
            bool ret = false;
            //travel left subtree and right subtree if needed
            if(NULL != root->left)
                ret |= work(root->left, sum, now);
            if(NULL != root->right)
                ret |= work(root->right, sum, now);
            return ret;
        }
}; 
