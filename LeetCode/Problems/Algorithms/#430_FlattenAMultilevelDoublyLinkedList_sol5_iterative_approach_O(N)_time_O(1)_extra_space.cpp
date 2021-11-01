/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        for(Node* node = head; node != NULL; node = node->next){
            if(node->child != NULL){
                Node* childTail = node->child;
                while(childTail->next != NULL){
                    childTail = childTail->next;
                }
                childTail->next = node->next;
                if(node->next != NULL){
                    node->next->prev = childTail;
                }
                
                node->next = node->child;
                node->child->prev = node;
                node->child = NULL;
            }
        }
        return head;
    }
};