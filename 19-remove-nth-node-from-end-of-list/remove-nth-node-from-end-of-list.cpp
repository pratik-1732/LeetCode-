/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL || head->next==NULL) return NULL;

        // int cnt=0; 
        // ListNode* temp= head;
        // while(temp!=NULL){
        //     cnt++;
        //     temp= temp->next;
        // }
        // int del= cnt-n;
        // if (del == 0) {
        //     ListNode* newHead = head->next;
        //     delete head; 
        //     return newHead; 
        // }
        // temp= head;
        // ListNode* prev= NULL;
        
        // while(del>0){
        //     prev= temp;
        //     temp= temp->next;
            
        //     del--;
        // }
        // prev->next= temp->next;
        // temp->next= NULL;
        // delete temp;

        ListNode* fast= head;
        ListNode* slow= head;

        for(int i=0; i<n; i++) fast= fast->next;
        if(fast==NULL){
            ListNode* newHead= head->next;
            delete head;
            return newHead;
        }
        while(fast->next!=NULL){
            fast= fast->next;
            slow= slow->next;
        }
        ListNode* del= slow->next;
        slow->next= slow->next->next;
        delete del;

        return head;
    }
};