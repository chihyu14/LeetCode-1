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
        //if root is NULL, empty tree
        if(NULL == root)
            return;
        //connect left subtree
        connect(root->left);
        //connect right subtree
        connect(root->right);
        //p is left-child of root
        //q is right-child of root
        TreeLinkNode *p = root->left;
        TreeLinkNode *q = root->right;
        //set the next such as 5->6 in the sample
        while(NULL != p)
            {
                //set p'x next to q;
                p->next = q;
                //p goes to the right
                //and q goes to the left
                p = p->right;
                q = q->left;
            }
    }
};/**
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
        //if root is NULL, empty tree
        if(NULL == root)
            return;
        //connect left subtree
        connect(root->left);
        //connect right subtree
        connect(root->right);
        //p is left-child of root
        //q is right-child of root
        TreeLinkNode *p = root->left;
        TreeLinkNode *q = root->right;
        //set the next such as 5->6 in the sample
        while(NULL != p)
            {
                //set p'x next to q;
                p->next = q;
                //p goes to the right
                //and q goes to the left
                p = p->right;
                q = q->left;
            }
    }
}; 
