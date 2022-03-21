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
        if(head == NULL){
            return NULL;
        }
        
        Node* node = head;
        while(node != NULL){
            Node* tempNode = node->next;
            node->next = new Node(node->val);
            node->next->next = tempNode;
            node = tempNode;
        }
        
        node = head;
        while(node != NULL){
            if(node->random != NULL){
                node->next->random = node->random->next;
            }
            node = node->next->next;
        }
        
        Node* headCopy = head->next;
        Node* p1 = head;
        Node* p2 = head->next;
        while(p2->next != NULL){
            p1->next = p1->next->next;
            p2->next = p2->next->next;
            p1 = p1->next;
            p2 = p2->next;
        }
        p1->next = NULL;
        
        return headCopy;
    }
};