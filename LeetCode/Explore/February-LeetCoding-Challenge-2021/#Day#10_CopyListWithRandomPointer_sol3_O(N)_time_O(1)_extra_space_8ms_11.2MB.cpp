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
        
        // Step 1: A -> ACopy -> B -> BCopy -> ..... -> Z -> ZCopy
        Node* node = head;
        Node* temp = NULL;
        for(Node* node = head; node != NULL; node = node->next->next){
            temp = node->next;
            node->next = new Node(node->val);
            node->next->next = temp;
        }
        
        // Step 2: update 'random' pointers (for each copy of original nodes)
        for(Node* node = head; node != NULL; node = node->next->next){
            if(node->random != NULL){
                node->next->random = node->random->next;
            }
        }
        
        // Step 3: update 'next' pointers (for original and copied nodes)
        //         A -> B -> ..... -> Z
        //         ACopy -> BCopy -> ... -> ZCopy
        Node* headCopy = head->next;
        Node* nodeCopy = NULL;
        for(Node* node = head; node != NULL; node = node->next){
            nodeCopy = node->next;
            node->next = node->next->next;
            if(nodeCopy->next != NULL){
                nodeCopy->next = nodeCopy->next->next;
            }
        }
        
        return headCopy;
    }
};