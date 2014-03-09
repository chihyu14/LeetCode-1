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
    ListNode *sortList(ListNode *head) {
        //meger sort
        //@c: total of list's element
        int c = 0;
        ListNode *k = head;
        while(NULL != k)
            {
                ++c;
                k = k->next;
            }
        //if list only has zero or one element
        if(c<2)
            return head;
        ////find the middle position
        c = c>>1;
        k=head;
        while(--c)
            k = k->next;
        //r point to the second part
        ListNode *r = k->next;
        k->next = NULL;//point k->next to NULL
        k = sortList(head);//sort first part
        r = sortList(r);//sort second part
        //@root: auxiluray node
        //@t: auxiluray node
        ListNode *root = new ListNode(0);
        ListNode *t = root;
        //loop the first sorted and second sorted parts
        while(NULL != k && NULL != r)
            {
                if(k->val < r->val)//add k->val into answer list
                    {
                        t->next = k;
                        k = k->next;
                    }
                else//add r->val into answer list
                    {
                        t->next = r;
                        r = r->next;
                    }
                t = t->next;//t move to next node
            }
        if(NULL != k)//add k to the end of the answer list if needed.
            {
                t->next = k;
            }
        if(NULL != r)//add r to the end of the answer list if needed.
            {
                t->next = r;
            }
        return root->next;//return the sorted list
    }
};