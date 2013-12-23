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
    int sumNumbers(TreeNode *root) {
        int ret = 0;
        //travel all the path
        work(root, ret, 0);
        return ret;
    }
    //@cur: the current node
    //@ret: the answer
    //@n: the number from root to the current node
    void work(TreeNode *cur, int &ret, int n)
        {
            //if cur is NULL
            if(NULL == cur)
                {
                    return ;
                }
            //update n
            n = 10*n + cur->val;
            //if cur is leaf node, then, update ret
            if(NULL == cur->left && NULL == cur->right)
                {
                    ret += n;
                    return;
                }
            //travel the left subtree
            if(NULL != cur->left)
                work(cur->left, ret, n);
            //travel the right subtree
            if(NULL != cur->right)
                work(cur->right, ret, n);
        }
};