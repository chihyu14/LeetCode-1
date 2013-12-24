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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        //@head: the tmp point 
        //@ret: the head of the answer ListNode
        ListNode *head = NULL, *ret;
        //@add: if(l1->val+l2->val > 9) add = 1
        //      else add = 0
        int add = 0;
        //while l1 doesn't reach the end and
        //      l2 doesn't reach the end
        while(l1 != NULL && l2 != NULL)
            {
                ListNode *tmp = new ListNode(l1->val+l2->val+add);
                //update *add* adn tmp->val if needed
                if(tmp->val > 9)
                    {
                        add = 1;
                        tmp->val %= 10;
                    }
                else
                    add = 0;
                //update the answer List
                if(NULL == head)
                    {// the answer list is empty now
                        head = tmp;
                        ret = head;
                    }
                else
                    {
                        head->next = tmp;
                        head = tmp;
                    }
                //move l1 and l2 on
                l1 = l1->next;
                l2 = l2->next;
            }
        //if l1 doesn't reach the end
        if(NULL = l1)	
	    l1 = l2;
        while(NULL != l1)
            {
                ListNode *tmp = new ListNode(l1->val + add);
                if(tmp->val > 9)
                    {
                        add = 1;
                        tmp->val %= 10;
                    }
                else
                    add = 0;
                if(NULL == head)
                    {
                        head = tmp;
                        ret = head;
                    }
                else
                    {
                        head->next = tmp;
                        head = tmp;
                    }
                l1 = l1->next;
            }
        /*
        //if l2 doesn't reach the end
        while(NULL != l2)
            {
                ListNode *tmp = new ListNode(l2->val + add);
                if(tmp->val > 9)
                    {
                        add = 1;
                        tmp->val %= 10;
                    }
                else
                    {
                        add = 0;
                    }
                if(head == NULL)
                    {
                        head = tmp;
                        ret = head;
                    }
                else
                    {
                        head->next = tmp;
                        head = tmp;
                    }
                l2 = l2->next;
            }
        */
        //if add is 1, we should add a new node to the answer list
        if(1 == add)
            {
                ListNode *tmp = new ListNode(1);
                head->next = tmp;
            }
        //return the answer
        return ret;
    }
}; 
