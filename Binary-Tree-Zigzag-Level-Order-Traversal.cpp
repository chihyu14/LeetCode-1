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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        if(NULL == root)
            return vector<vector<int> >();
        vector<vector<int> > ret;
        vector<TreeNode*> l;
        l.push_back(root);
        work(l, ret, 0);
        return ret;
    }
    //travel the tree level by level
    //@l: the current level 
    //@ret: answer
    //@lev: flag  0-->odd level  1-->even level
    void work(vector<TreeNode*> l, vector<vector<int> > &ret, int lev)
    {
        vector<int> tmp;
        vector<TreeNode*> next;
        if(lev&1)
        {
            //even level, travel right to left
            for(int i=l.size()-1; i>=0; --i)
                {
                    tmp.push_back(l[i]->val);
                }
            if(tmp.size() != 0)
                ret.push_back(tmp);
            for(int i=0; i<l.size(); ++i)
                {
                    if(NULL != l[i]->left)
                        next.push_back(l[i]->left);
                    if(NULL != l[i]->right)
                        next.push_back(l[i]->right);
                }
            if(next.size() != 0)
                work(next, ret, 1^lev);
        }
        else
        {
            //odd level, travel left to right
            for(int i=0; i<l.size(); ++i)
                {
                    tmp.push_back(l[i]->val);
                }
            if(0 != tmp.size())
                ret.push_back(tmp);
            for(int i=0; i<l.size(); ++i)
            {
                if(NULL != l[i]->left)
                        next.push_back(l[i]->left);
                    if(NULL != l[i]->right)
                        next.push_back(l[i]->right);
            }
            if(0 != next.size())
                work(next, ret, 1^lev);
        }
        
    }
};
