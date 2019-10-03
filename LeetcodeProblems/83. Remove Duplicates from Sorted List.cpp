// Runtime: 16 ms
// Memory Usage: 9.3 MB

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
        ListNode* now=head;

        while (now!=NULL)
        {
            ListNode* t=now->next;
            while (t!=NULL && t->val == now->val)
                t=t->next;
            now->next=t;
            now=t;
        }
        
        return head;
    }
};