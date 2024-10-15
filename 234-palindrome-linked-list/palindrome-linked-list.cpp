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
    bool isPalindrome(ListNode* head) {
        stack<int> st;
        ListNode* temp= head;
        while(temp!=NULL){
            st.push(temp->val);
            temp= temp->next;
        }
        bool flag= false;
        temp= head;
        while(temp!=NULL){
            int data= st.top();
            st.pop();
            if(temp->val!= data) return flag;

            temp= temp->next;
        }
        flag= true;

        return flag;
    }
};