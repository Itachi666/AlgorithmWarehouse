// Runtime: 20 ms
// Memory Usage: 10.2 MB

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
    ListNode* reverse(ListNode* last, int k){
        ListNode *i,*j,*x,*y,*z,*now,*nlast, *needreturn=last->next;
        i=last;
        for (int t=0; t<k;t++)
        {
            if (i->next==NULL)
                return i;
            i=i->next;
        }
        nlast=i->next;
        
        z=last->next;
        now=z->next;
        z->next=nlast;
            
        while (now!=i)
        {
            y=now->next;
            now->next=z;
            
            z=now;
            now=y;
        }
        
        now->next=z;
        last->next=now;
                
        return needreturn;
    }
    
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k<=1)
            return head;
        ListNode* answer=new ListNode(0);
        answer->next=head;
        ListNode* last=answer;
        while (last->next!=NULL)
            last=reverse(last,k);
        return answer->next;
    }
};