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
    ListNode *reverseKGroup(ListNode *head, int k) {
        //empty list or k==1
        if(NULL == head || 1== k)
            return head;
        //add a node in the front of the head
        //so we could do it convenient
        ListNode *root = new ListNode(0);
        root->next = head;
        work(head, root, k, 1);
        //return the head of the list
        return root->next;
    }
    //@cur: current node
    //@start: the node before this group
    //@k: the same as the problem
    //@cnt: how many nodes we have scanned of the current group
    void work(ListNode *cur, ListNode *start, int k, int cnt)
    {
        //the end of the list
        if(NULL == cur)
            return;
        //we have scanned a group
        if(cnt == k)
            {
                //reverse the right nodes of the list
                work(cur->next, cur, k, 1);
                //reverse the current group
                ListNode *p, *q, *t, *end;
                p = start->next;
                end = cur->next;
                q = p->next;
                while(q != end)
                    {
                        t = q->next;
                        q->next = p;
                        p = q;
                        q = t;
                    }
                q = start->next;
                q->next = end;
                start->next = p;
            }
        else
            work(cur->next, start, k, cnt+1);
    }
};