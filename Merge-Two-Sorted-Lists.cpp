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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        //if l1 or l2 is NULL
        //return the other one
        if(NULL == l1) 
            return l2;
        if(NULL == l2)
            return l1;
        //head is the head of the new list
        //scan is used for the loop
        ListNode *head, *scan;
        //set the head
        if(l1->val < l2->val)
            {
                head = l1;
                l1 = l1->next;
            }
        else
            {
                head = l2;
                l2 = l2->next;
            }
        scan = head;
        ///the main loop
        while((NULL != l1) && (NULL != l2))
            {
                //find the smaller val
                //add it to the new list
                if(l1->val < l2->val)
                    {
                        scan->next = l1;
                        l1 = l1->next;
                    }
                else
                    {
                        scan->next = l2;
                        l2 = l2->next;
                    }
                //move to the next node
                scan = scan->next;
            }
        //if l1 is not NULL, add it to the new list
        if(NULL != l1)
            scan->next = l1;
        //same as above, it can't be (NULL != l1 && NULL != l2)!!!!
        if(NULL != l2)
            scan->next = l2;
        return head;
    }
}; 
