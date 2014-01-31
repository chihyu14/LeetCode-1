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
    void reorderList(ListNode *head) {
        
        if(NULL == head)
            return;
        ListNode *root = new ListNode(0);
        
        root->next = NULL;
        ListNode *tmp = head, *pre, *t;
        int k=0;
        //@k: length of list
        for(; tmp != NULL; ++k)
            tmp = tmp->next;
        k = k>>1;
        tmp=head;
        //find the last half part
        for(int i=0; i<k; ++i)
            tmp = tmp->next;
        
        pre = tmp->next;
        tmp->next = NULL;
        
        //reorder the last half part
        while(NULL != pre)
            {
                t = pre->next;
                pre->next = root->next;
                root->next = pre;
                pre = t;
            }
        pre=head, tmp=head;
        
        //jion the two lists
        while(pre != NULL)
        {
            tmp = pre->next;
            if(NULL == root->next)//all nodes have been added to the ordinary list
                break;
                
            //add the current node
            pre->next = root->next;
            t = root->next;
            root->next = t->next;
            t->next = tmp;
            pre = tmp;
        }
    }
};
