/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        //@root: auxiliary node!!!!
        ListNode *root = new ListNode(0);
        root->next = head;
        //@pre: previous node of current node
        ListNode *pre = root;
        //@the end of the first partition
        ListNode *before = root;
        //pass over all the nodes don't need to rearrange!!!!
        while(head)
            {
                if(head->val < x)
                    {
                        pre = head;
                        head = head->next;
                        before = pre;
                    }
                else
                    break;
            }
        //partition the list into two partitions
        while(head)
        {
            if(head->val < x)
                {//move current node to the first partition
                    ListNode *last = head->next;
                    pre->next =head->next;
                    head->next = before->next;
                    before->next = head;
                    before = head;
                    head = last;
                    //if(pre == root)
                    //    pre = root->next;
                }
            else
                {
                    pre = head;
                    head = head->next;
                }
        }
        return root->next;
    }
};