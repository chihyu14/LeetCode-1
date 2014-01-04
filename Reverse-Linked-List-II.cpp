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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        //@root: the m-th node
        //@pre: the (m-1)-th node (if m>1)
        ListNode *root = head, *pre = head;
        int k=1;
        //find root and pre
        while(k<m)
            {
                root = root->next;
                if(1 != k)
                    pre = pre->next;
                ++k;
            }
        ListNode *p, *q, *t;
        //k = 1;
        p = root;
        q = root->next;
        //reverse the list betweein [m,n]
        while(k<n)
            {
                t = q->next;
                q->next = p;
                p = q;
                q = t;
                ++k;
            }
        root->next = q;
        if(m>1) //if m>1 such as above (1->2->3->4->5 and m=2, n= 4)
            pre->next = p;
        else    //else update head
            {   //such as (1->2->3->4->5 and m=1, n=4)
                head = p;
            }
        return head;
    }
};