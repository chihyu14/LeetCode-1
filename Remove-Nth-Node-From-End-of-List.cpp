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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        //use recursion to locate the nth node from the end
        int t = work(head, n+1);
        //remove the first node
        if(n == t)
            return head->next;
        return head;
    }
    //return the location of cur from the end
    int work(ListNode *cur, int n)
    {
        if(NULL == cur)
            return 0;
        int t = work(cur->next, n);
        //update the current location
        ++t;
        //delete this node
        if(t == n)
            {
                ListNode *tmp = cur->next;
                cur->next = tmp->next;
            }
        return t;
    }
}; 
