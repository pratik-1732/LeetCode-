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
    ListNode *findPoint(ListNode *fast, ListNode *temp){
        while(fast!=temp){
            temp= temp->next;
            fast= fast->next;
        }
        return fast;
    }
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL||head->next==NULL) return NULL;

        ListNode* fast= head;
        ListNode* slow= head;

        while(fast!=NULL && fast->next!=NULL){
            slow= slow->next;
            fast= fast->next->next;

            if(slow==fast){
                return findPoint(fast, head);
            }
        }

        return NULL;
    }
};