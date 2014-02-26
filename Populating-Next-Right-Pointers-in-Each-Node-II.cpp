/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        //empty tree
        if(NULL == root)
            return;
        //do it level by level
         vector<TreeLinkNode *> f;
         //first level(root)
         f.push_back(root);
         work(f);  
    }
    //@lev: all elements of current level(left to right)
    void work(vector<TreeLinkNode *> lev)
    {
        //empty level
        if(0 == lev.size())
            return;
        //@next: all elements of next level
        vector<TreeLinkNode *> next;
        int size = lev.size();
        //set all the next pointer of the current level elements
        for(int i=0; i<size-1; ++i)
        {
            lev[i]->next = lev[i+1];
            //add child-node into next if it's NULL
            if(lev[i]->left != NULL)
                next.push_back(lev[i]->left);
            if(lev[i]->right != NULL)
                next.push_back(lev[i]->right);
        }
        //add child-node into next if it's NULL
        if(lev[size-1]->left != NULL)
            next.push_back(lev[size-1]->left);
        if(lev[size-1]->right != NULL)
            next.push_back(lev[size-1]->right);
        //handle next level
        work(next);
    }
};