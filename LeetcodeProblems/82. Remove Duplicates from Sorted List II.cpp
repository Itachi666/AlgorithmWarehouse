// Runtime: 8 ms
// Memory Usage: 9.1 MB

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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head==NULL || head->next==NULL)
            return head;
        
        bool rmhead=false;
        if (head->val==head->next->val)
            rmhead=true;
               
        ListNode* now=head;
        ListNode* last=head;

        while (now!=NULL)
        {
            if (now->next==NULL)
                break;
            if (now->next->val==now->val)
            {
                while (now->next!=NULL && now->next->val==now->val)
                    now=now->next;
                last->next=now->next;
                now=now->next;
            }
            else
            {
                last=now;
                now=now->next;
            }
        }
        
        if (rmhead) 
            head=head->next;
        
        return head;
    }
};