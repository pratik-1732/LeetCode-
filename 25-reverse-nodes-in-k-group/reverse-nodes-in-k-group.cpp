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
    ListNode* reverse(ListNode* tempHead){
        ListNode* tem= tempHead;
        ListNode* prev= NULL;
        while(tem!=NULL){
            ListNode* front= tem->next;
            tem->next= prev;
            prev= tem;
            tem= front;
        }
        return prev;
    }
    ListNode* findNode(ListNode* temp, int k){
        int cnt=1;
        ListNode* kNode= temp;
        while(cnt!=k && kNode!=NULL){
            kNode= kNode->next;
            cnt++;
        }
        if(cnt==k) return kNode;
        else return NULL;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL || head->next==NULL) return head;

        ListNode* temp= head;
        ListNode* nextNode=NULL; ListNode* prevNode= NULL;

        while(temp!=NULL){
            ListNode* kNode= findNode(temp, k);
            if(kNode==NULL){
                if(prevNode!=NULL) prevNode->next= temp;
                break;
            }
            // cout<<kNode->val<<" ";

            nextNode= kNode->next;
            kNode->next= NULL;

            reverse(temp);
          
            if(temp==head) head= kNode;
            else{
                prevNode->next= kNode;
            }
            prevNode= temp;
            temp= nextNode;
        }

        return head;
    }
};