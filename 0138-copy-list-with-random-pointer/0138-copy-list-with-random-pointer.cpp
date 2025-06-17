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
        Node* temp = head;
        
        while(temp != NULL){
            Node* copynode = new Node(temp->val);
            copynode->next = temp->next;
            temp->next = copynode;

            temp = temp->next->next;
        }

        temp = head;

        while(temp != NULL){
            Node* copynode = temp->next;
            if(temp->random){
                copynode->random = temp->random->next;
            }
            else{
                copynode->random = NULL;
            }

            temp = temp->next->next;
        }

        temp = head;
        Node* dummy = new Node(-1);
        Node* res = dummy;

        while(temp != NULL){
            res->next = temp->next;
            temp->next = temp->next->next;
            
            res = res->next;
            temp = temp->next;
        }
        return dummy->next;
    }
};