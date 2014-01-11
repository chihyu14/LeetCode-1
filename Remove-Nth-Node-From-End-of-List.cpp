/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //Solution 1
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
//Solution 2
//first, let p1 point to the k-th node, p2 point to the first node,
//then, move p1 and p2 the same time. when p1 reaches the end, the node
//p2 points to is we want.