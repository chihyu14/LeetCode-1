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
    ListNode *swapPairs(ListNode *head) {
        //if list is empty or 
        //it has only one element
        if(NULL == head)
            return NULL;
        if(NULL == head->next)
            return head;
        //first: the first of the two elements
        //second: the second of the two elements
        //last: the element before the first
        ListNode *first, *second, *last=NULL;
        ListNode *tmp = head;
        //head: the answer will return
        head = head->next;
        //main loop
        while(NULL != tmp)
            {
                //get first and second
                first = tmp;
                second = tmp->next;
                if(NULL == second)
                    {//if the amount of the list is odd
                        break;
                    }
                //the begeinning of the list
                if(NULL == last)
                    {//the first two 
                        first->next = second->next;
                        second->next = first;
                    }
                else
                    {
                        last->next = second;
                        first->next = second->next;
                        second->next = first;
                    }
                //update the last and tmp
                //because we swap first and second, 
                //so tmp = tmp->next not tmp->next->next!!!!
                last = first;
                tmp = tmp->next;
            }
        //return the answer!!
        return head;
    }
}; 
