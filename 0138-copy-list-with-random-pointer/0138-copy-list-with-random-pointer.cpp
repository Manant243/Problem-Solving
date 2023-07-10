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
        Node* iter = head;
        
        while(iter != NULL){
            Node* copy = new Node(iter->val);
            copy->next = iter->next;
            iter->next = copy;
            iter = iter->next->next;
        }
        
        iter = head;
        while(iter != NULL){
            if(iter->random != NULL){
                iter->next->random = iter->random->next;
            }
            iter = iter->next->next;
        }
        
        iter = head;
        Node* dummy = new Node(0);
        Node* copy = dummy;
        
        while(iter != NULL){
            copy->next = iter->next;
            copy = copy->next;
            iter->next = copy->next;
            iter = iter->next;
        }
        
        return dummy->next;
    }
};