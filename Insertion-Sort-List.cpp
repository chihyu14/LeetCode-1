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
    ListNode *insertionSortList(ListNode *head) {
        //empty list
        if(NULL == head)
            return head;
        //@root: head of sorted list
        ListNode *root = new ListNode(0);
        //add the first node to the sorted list,
        //and remove it form the ordinary list
        root->next = head;
        head = head->next;
        root->next->next = NULL; //add NULL in the end of the sorted list
        //sort all the left list
        while(head != NULL)
        {
            ListNode *pre = root;
            ListNode *t = root->next;
            //find the right position
            while(NULL != t)
            {
                if(t->val >= head->val)
                    break;
                pre = t;
                t = t->next;
            }
            //add the node to the sorted list,
            //and remove it from the ordinary list
            pre->next = head;
            pre = head->next;
            head->next = t;
            head = pre;
        }
        //return the sorted list
        return root->next;
    }
};
