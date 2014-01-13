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
        //@root: auxiliary node!!!!
        ListNode *root = new ListNode(0);
        root->next = head;
        
        //@pre: previous node
        //@first: first node of each val
        //@second: nodes which value equals to first->val(after first!!!)
        ListNode *pre, *first, *second;
        pre = root;
        first = head;
        //while first != NULL and first has next node
        while(first && first->next)
        {
            //update second
            second = first->next;
            //@t: flag of duplicates (t=0 ---> no duplicates else have duplicates)
            int t = 0;
            while(second && (first->val == second->val))
                {
                    ++t;
                    second = second->next;
                }
            if(0 != t)//have duplicates which value is first->val
                {//remove these duplicates
                    pre->next = second;
                }
            else
                {//update pointer pre
                    pre = first;
                }
            first = second;//move to the next node
        }
        //return head!!!
        return root->next;
    }
};