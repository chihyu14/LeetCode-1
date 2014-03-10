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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        //@s: size of inorder
        //@l: size of postorder
        //s must equals to l
        int s = inorder.size();
        int l = postorder.size();
        //if(s == 0)//
        //    return NULL;
        //build tree
        TreeNode *root = work(inorder, 0, s-1, postorder, 0, l-1);
        return root;
    }
    //@inorder: the given inorder vector
    //@istart: the begin index of inorder
    //@iend: the end index(include) of inorder
    //@postorder: the given postorder vector
    //@pstart: the begin index of postorder
    //@pend: the end index(include) of postorder
    TreeNode *work(const vector<int> &inorder, int istart, int iend, vector<int> &postorder, int pstart, int pend)
    {
        //empty tree
        if(iend<istart)
            return NULL;
        //@root: the root of current tree
        TreeNode *root = new TreeNode(postorder[pend]);
        if(istart == iend)////it only has a single node
            return root;
        //@x: elements amount in root's left subtree
        int x = 0;
        for(int i=istart; i<=iend; ++i)
            {
                if(inorder[i] == postorder[pend])
                    break;
                ++x;
            }
        //build two subtrees
        root->left = work(inorder, istart, istart+x-1, postorder, pstart, pstart+x-1);
        root->right = work(inorder, istart+x+1, iend, postorder, pstart+x, pend-1);
        //return root
        return root;
    }
};