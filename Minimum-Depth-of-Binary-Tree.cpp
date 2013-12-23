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
    int minDepth(TreeNode *root) {
        int ret = INT_MAX;
        work(root, ret, 0);
        if(ret == INT_MAX)
            ret = 0;
        return ret;
    }
    void work(TreeNode *cur, int &ret, int n)
    {
        if(NULL == cur)
            return;
        ++n;
        if(NULL == cur->left && NULL == cur->right)
            {
                if(n < ret)
                    ret = n;
                return;
            }
        if(NULL != cur->left)
            work(cur->left, ret, n);
        if(NULL != cur->right)
            work(cur->right, ret, n);
    }
};