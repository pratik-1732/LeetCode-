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
    bool hasCycle(ListNode *head) {
        if(head==NULL || head->next==NULL) return false;

        unordered_set<ListNode*> check;

        ListNode* temp= head;
        while(temp!=NULL){
            if(check.find(temp)!=check.end()) return true;
            check.insert(temp);
            temp= temp->next;
        }
        return false;
    }
};