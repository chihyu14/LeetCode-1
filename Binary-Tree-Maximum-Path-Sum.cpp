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
    int maxPathSum(TreeNode *root) {
        //@ret: answer we will return
        int ret = INT_MIN;
        work(root, ret);
        return ret;
    }
    //@root: current node
    //@ans: final answer
    int work(TreeNode *root, int &ans)
    {
        //if root is an empty tree
        if(NULL == root)
            return 0;
        //if root is leaf node
        if(NULL == root->left && NULL == root->right)
        {
            //update ans if needed
            if(root->val > ans)
                ans = root->val;
            return root->val;
        }
        //@l: the maximum sum of left subtree(from root->left to some leaf node)
        //@r: the maximum sum of right subtree(from root->right to some leaf node)
        int l = work(root->left, ans);
        int r = work(root->right, ans);
        //@ret: the maximum path sum that include current node
        int ret = root->val;
        if(l>0)
            ret += l;
        if(r>0)
            ret += r;
        if(ret>ans)//update ans if needed
            ans = ret;
        //return maximum sum of the current tree(from root to some leaf node)
        return max(0, max(l, r))+root->val;
    }
};