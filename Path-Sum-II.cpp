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
    //same as Path Sum
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int> > ret;
        work(root, sum, 0, ret, vector<int>());
        return ret;
    }
    void work(TreeNode *cur, int sum, int now, vector<vector<int> > &ret, vector<int> tmp)
    {
        //current node is NULL
        if(NULL == cur)
            {
                return ;
            }
            
        //add cur->val to the vector
        tmp.push_back(cur->val);
        //update now
        now += cur->val;
        
        //if cur is a leaf node
        if(NULL == cur->left && NULL == cur->right)
            {
                //update ret if needed
                if(now == sum) 
                    ret.push_back(tmp);
                return ;
            }
        //travel the sub tree if needed
        if(NULL != cur->left)
            work(cur->left, sum, now, ret, tmp);
        if(NULL != cur->right)
            work(cur->right, sum, now, ret, tmp);
    }
};