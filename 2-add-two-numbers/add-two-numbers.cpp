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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy= new ListNode(-1);
        ListNode* curr= dummy;
        int carry=0;
        while(l1!=NULL || l2!=NULL){
            int sum = carry;
            if(l1!=NULL) sum+= l1->val;
            if(l2!=NULL) sum+= l2->val;
            
            ListNode* temp= new ListNode(sum%10);
            curr->next= temp;
            curr= temp;
            carry= sum/10;

            if(l1!=NULL) l1= l1->next;
            if(l2!=NULL) l2= l2->next;
        }

        if(carry!=0){
            ListNode* temp= new ListNode(carry);
            curr->next= temp;
        }

        return dummy->next;
    }
};