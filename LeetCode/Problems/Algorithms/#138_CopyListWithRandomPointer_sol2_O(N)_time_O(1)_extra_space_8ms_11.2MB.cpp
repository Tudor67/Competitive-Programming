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
        
        // Step 1: interweave original and copied nodes
        //         A -> A' -> B -> B' ...
        for(Node* node = head; node != NULL; node = node->next->next){
            Node* nodeCopy = new Node(node->val);
            nodeCopy->next = node->next;
            nodeCopy->random = node->random;
            node->next = nodeCopy;
        }
        
        // Step 2: update 'random' links of the copied nodes
        Node* nodeCopy = head->next;
        while(nodeCopy != NULL){
            if(nodeCopy->random != NULL){
                nodeCopy->random = nodeCopy->random->next;
            }
            if(nodeCopy->next == NULL || nodeCopy->next->next == NULL){
                break;
            }else{
                nodeCopy = nodeCopy->next->next;
            }
        }
        
        // Step 3: split the interweaved list into original and copied lists
        //        (i.e., update 'next' links of both lists)
        Node* headCopy = head->next;
        Node* node = head;
        while(node != NULL){
            Node* nodeCopy = node->next;
            node->next = node->next->next;
            if(nodeCopy != NULL && nodeCopy->next && nodeCopy->next->next != NULL){
                nodeCopy->next = nodeCopy->next->next;
            }
            if(node->next != NULL){
                node = node->next;
            }else{
                break;
            }
        }
        
        return headCopy;
    }
};