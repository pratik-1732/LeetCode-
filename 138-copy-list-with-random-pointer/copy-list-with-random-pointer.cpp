/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* temp= head;
        while(temp!=NULL){
            Node* copy= new Node(temp->val);
            copy->next= temp->next;
            temp->next= copy;

            temp= temp->next->next;
        }
        temp= head;
        Node* dNode= new Node(-1);
        Node* res= dNode;
    
        while(temp!=NULL){
            Node* copy= temp->next;
            
            if(temp->random) copy->random= temp->random->next;
            else copy->random= NULL;

            temp= temp->next->next;

        }

        temp= head;
        while(temp!=NULL){
            Node* copy= temp->next;
            res->next= copy;
            res= res->next;
            temp->next= copy->next;

            temp= temp->next;
        }

        return dNode->next;
    }
};