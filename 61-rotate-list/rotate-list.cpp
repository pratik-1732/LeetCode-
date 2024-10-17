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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL) return head;
    
        ListNode* temp= head;
        ListNode* tail= head;
        int len=1;

        while(tail->next!=NULL){
            len++;
            tail= tail->next;
        }
        if(k%len==0) return head;

        k%=len;
        int cnt= len-k-1;
        tail->next= head;
        while(cnt>0){
            cnt--;
            temp= temp->next;
        }
        ListNode* newHead= temp->next;
        temp->next= NULL;

        return newHead;
    }
};