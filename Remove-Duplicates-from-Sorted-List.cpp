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
    ListNode *deleteDuplicates(ListNode *head) {
        //first points to the head of the List
        ListNode *first = head;
        //while fist is neither the last node, nor the NULL
        //progress!!!!
        //WARNING: first may be NULL, because of (first=second)!!!!!!!!!
        while((NULL != first) && (NULL != first->next))
            {
                //second is the next node of first
                ListNode *second = first->next;
                //while second is not NULL
                //and second->val equals to first->val(the list is sorted!!!!!)
                while((NULL != second) && (first->val == second->val))
                    second = second->next;
                //adjusts the list, removes the duplicates
                first->next = second;
                //let first be second to progress next loop
                first = second;
            }
        //return the head of the list
        return head;
    }
};