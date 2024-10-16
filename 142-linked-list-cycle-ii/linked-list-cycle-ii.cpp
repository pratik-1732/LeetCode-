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
        if(head==NULL||head->next==NULL) return NULL;

        unordered_set<ListNode*> check;

        ListNode* temp= head;
        while(temp!=NULL){
            if(check.find(temp)!=check.end()) {
                return temp;
            }
            else check.insert(temp);

            temp= temp->next;
        }

        return NULL;
    }
};