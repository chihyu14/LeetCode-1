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
    vector<int> preorderTraversal(TreeNode *root) {
        ///@ret: answer
        vector<int> ret;
        if(NULL == root)
            return ret;
        //@st: stack contains TreeNodes
        stack<TreeNode*> st;
        //push every node twice, so we could precess its two subtrees
        st.push(root);
        st.push(root);
        //push the answer
        ret.push_back(root->val);
        while(!st.empty())
            {
                //pop the top node
                TreeNode *tmp = st.top();
                st.pop();
                //if we process this node the first time
                if(!st.empty() && tmp == st.top())
                    {
                        if(NULL != tmp->left)
                            {//process left subtree if needed
                                st.push(tmp->left);
                                st.push(tmp->left);
                                ret.push_back(tmp->left->val);
                            }
                    }
                else
                    {
                        if(NULL != tmp->right)
                            {//process right subtree if needed
                                st.push(tmp->right);
                                st.push(tmp->right);
                                ret.push_back(tmp->right->val);
                            }
                    }
            }
        return ret;
    }
};