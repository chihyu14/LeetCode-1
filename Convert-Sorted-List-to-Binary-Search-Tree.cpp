/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode *sortedListToBST(ListNode *head) {
        //empyt list
        if(NULL == head)
            return NULL;
        //@l: length of list
        int l = 0;
        ListNode *root = head;
        while(NULL != root)
            {
                ++l;
                root = root->next;
            }
        //find the middle point
        l = (l>>1);
        
        //add a root before the list
        root = new ListNode(0);
        root->next = head;
        ListNode *t = root;
        //find the root point of the current list
        while(l--)
        {
            root = root->next;
        }
        ListNode *right = root->next;
        root->next = NULL;
        TreeNode *ret = new TreeNode(right->val);
        //set left subtree and right subtree
        ret->left = sortedListToBST(t->next);
        ret->right = sortedListToBST(right->next);
        return ret;
    }
};