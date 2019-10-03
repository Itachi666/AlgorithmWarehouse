// Runtime: 164 ms
// Memory Usage: 11.6 MB

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* answer;
        bool mark;
        
        if (l1==NULL)
            return l2;
        if (l2==NULL)
            return l1;
        
        if (l1->val<=l2->val)
        {
            answer=l1;
            mark=false;
        }
        else
        {
            answer=l2;
            mark=true;
        }
        
        //string listNodeToString(ListNode* node);
        
        
        while (l1!=NULL && l2!=NULL)
        {
            if (mark)
            {
                while (l2->next!=NULL && l2->next->val<=l1->val )
                    l2=l2->next;
                ListNode* t=l2;
                l2=l2->next;
                t->next=l1;
                mark=!mark;
            }
            else
            {
                while (l1->next!=NULL && l1->next->val<=l2->val)
                    l1=l1->next;
                //cout<<listNodeToString(l1)<<endl;
                ListNode* t=l1;
                l1=l1->next;
                t->next=l2;
                mark=!mark;
            }
            //cout<<listNodeToString(answer)<<' '<<listNodeToString(l1)<<' '<<listNodeToString(l2)<<endl;
            
        }
        return answer;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* answer=NULL;
        if (lists.size()==0)
            return answer;
        answer=lists[0];
        for (int i=1;i<lists.size();i++)
            answer=mergeTwoLists(answer,lists[i]);
        return answer;
    }
};