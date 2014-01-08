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
    TreeNode *sortedArrayToBST(vector<int> &num) {
        int size = num.size();
        //empty array
        if(0 == size)
            return NULL;
        return work(num, 0, size-1);
    }
    //@num: array
    //@beg: the begin index(include)
    //@end: the end index(include)
    TreeNode* work(const vector<int> &num, int beg, int end)
    {
        //beg > end
        if(beg>end)
            return NULL;
        TreeNode *node;
        //only one element
        if(beg == end)
            {
                node = new TreeNode(num[beg]);
            }
        else
            {
                //get the middle of the range [beg,end]
                int mid = (beg+end)>>1;
                //create a node for mid
                node = new TreeNode(num[mid]);
                //create left and right subtree
                node->left = work(num, beg, mid-1);
                node->right = work(num, mid+1, end);
            }
        return node;
        
    }
};