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
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> ret;
        if(NULL == root)
            return ret;
        stack<pair<TreeNode*, int> > st;
        st.push(make_pair(root, 2));
        //st.pop();
        while(!st.empty())
            {
                pair<TreeNode*, int> tmp = st.top();
                st.pop();
                if(0 == tmp.second)//print this node
                    {
                 //       st.pop();
                        ret.push_back((tmp.first)->val);
                        continue;
                    }
                if(2 == tmp.second)//process left subtree
                    {
		        //push this node back into the stack
                        st.push(make_pair(tmp.first, 1));
                        if(NULL != (tmp.first)->left)
                            st.push(make_pair((tmp.first)->left, 2));
                    }
                else
                    {///process right subtree
                      //push this node back into the stack  
		      st.push(make_pair(tmp.first, 0));
                        if(NULL != (tmp.first)->right)
                            st.push(make_pair((tmp.first)->right, 2));
                    }
            }
        return ret;
    }
};