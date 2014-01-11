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
    ListNode *detectCycle(ListNode *head) {
        //fast runner and slow runner(1-step and 2-steps)
        //the total steps that fast runner used to catch slow runner
        //is a multiply of the length of the circle!!!!!!
        ListNode *first, *second;
        //@root: add a new node, so we shouldn't process the empty list
        ListNode *root = new ListNode(0);
        root->next = head;
        first = root;
        second = head;
        while(NULL != first && NULL != second)
            {
                //first == second  ----> there is a cycle
                if(first == second)
                    break;
                first = first->next;
                second = second->next;
                if(NULL != second)//move to second->next->next if it exist
                    second = second->next;
            }
        //if there isn't a cycle
        if(NULL == second)
            return NULL;
        //@k: the length of the cycle
        int k = 1;
        //start from the same place and trave another loop
        //it uses *k* steps for second to catch first, where k is the length of the cycle
        first = first->next;
        second = second->next;
        second = second->next;
        while(first != second)
            {
                first = first->next;
                second = second->next;
                second = second->next;//we don't need to test if second is NULL!!!!!
                ++k;
            }
        //@l: the total steps we use to reverse the list, it equals to 2*x + k, x is the length cycle beginning 
        //and list's head, k is the length of the cycly
        int l = 0;
        first = head;
        second = first->next;
        head->next = NULL;
        while(NULL != second)
            {//reverse the list to calculate l
                ListNode *t = second->next;
                second->next = first;
                first = second;
                second = t;
                ++l;
            }
        //reverse the list 
        first = head;
        second = first->next;
        head->next = NULL;
        while(NULL != second)
            {
                ListNode *t = second->next;
                second->next = first;
                first = second;
                second = t;
            }
        //l = 2*x + k  ----> x=(l-k)/2
        l = (l-k)>>1;
        //find the beginning of the cycle
        first = head;
        while(l)
            {
                first = first->next;
                --l;
            }
        return first;
    }
};