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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        //@s: size of inorder
        //@l: size of preorder
        //s must equals to l
        int s = inorder.size();
        int l = preorder.size();
        TreeNode *root = work(inorder, 0, s-1, preorder, 0, l-1);
        return root;
    }
    //@inorder: the given inorder vector
    //@istart: the begin index of inorder
    //@iend: the end index(include) of inorder
    //@preorder: the given preorder vector
    //@pstart: the begin index of preorder
    //@pend: the end index(include) of preorder
    TreeNode *work(const vector<int> &inorder, int istart, int iend, vector<int> &preorder, int pstart, int pend)
    {
        //empty tree
        if(iend<istart)
            return NULL;
        //@root: the root of current tree
        TreeNode *root = new TreeNode(preorder[pstart]);
        if(istart == iend)////it only has a single node
            return root;
        //@x: elements amount in root's left subtree
        int x = 0;
        for(int i=istart; i<=iend; ++i)
            {
                if(inorder[i] == preorder[pstart])
                    break;
                ++x;
            }
        //build two subtrees
        root->left = work(inorder, istart, istart+x-1, preorder, pstart+1, pstart+x);
        root->right = work(inorder, istart+x+1, iend, preorder, pstart+x+1, pend);
        //return root
        return root;
    }
};