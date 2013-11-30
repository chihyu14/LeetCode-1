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
    bool hasCycle(ListNode *head) {
        ////p and q are both point to the head of the list
        ListNode *p = head;
        ListNode *q = head;
        
	//if List is empty, then return false
        if(NULL == head)	
            return false;
        //while p doesn't equal to q
	//use do-while instead of while
	//to process the single element
	//list
        do
            {
                //p moves to its next 
	        //we don't need to check
	        //whether p is NULL
	        //because q moves fast
	        //than p.
                p = p->next;
                //q moves to the next of its next
                //if it exits.
		//check q equals to NULL or not
		if(NULL != q)
                    q = q->next;
                //if q's next isn't NULL
		if(NULL != q)
                    q = q->next;
            }while(p != q);
        if(NULL == p)	//if p and q are both equal to NULL
            return false;
        return true;	//the list has a cycle.
    }
};