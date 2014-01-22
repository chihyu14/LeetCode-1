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
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        //empty list
        if(lists.size() == 0)
            return NULL;
        //@root: travel point
        //@head: sorted list head
        ListNode *root, *head;
        root = new ListNode(0);
        head = root;
        while(true)//sort
        {
            int idx;
            //find the first not NULL list
            for(idx = 0; idx < lists.size(); ++idx)
                if(lists[idx] != NULL)
                    break;
            //if all lists have been added to sorted list
            if(idx == lists.size())
                break;
            //find the smallest value hasn't been added to the sorted list
            for(int i=idx+1; i<lists.size(); ++i)
                {
                    if(lists[i] && lists[i]->val < lists[idx]->val)
                        idx = i;
                }
            //add this node to sorted list and remove it from Original list
            root->next = lists[idx];
            lists[idx] = lists[idx]->next;
            root = root->next;
        }
        //add NULL in the end of the sorted list
        root->next = NULL;
        //return the sorted list
        return head->next;
    }
};
