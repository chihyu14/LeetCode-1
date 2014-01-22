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
    ListNode *rotateRight(ListNode *head, int k) {
        if(NULL == head)
            return NULL;
        int l = 0;
        //get list's length
        ListNode *p = head;
        while(p)
            {
                ++l;
                p = p->next;
            }
        //k <=== k mod l
        k %= l;
        if(0 == k)//don't need rotate
            return head;
        ListNode  *q;
        p = head;
        q = head;
        //------------------------------------------------------------//
        //begin getting the kth node from end
        for(int i=0; i<=k; ++i)
        {
            q = q->next;
        }
        while(q)
            {
                p = p->next;
                q = q->next;
            }
        //end 
        //------------------------------------------------------------//
        //rotate the list
        ListNode *t = p->next;
        q = t;
        p->next = NULL;
        while(t->next)
            t = t->next;
        t->next = head;
        return q;
    }
};
