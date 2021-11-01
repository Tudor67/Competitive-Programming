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
private:
    void dfs(Node*& node){
        if(node == NULL){
            return;
        }
        if(node->child == NULL){
            if(node->next != NULL){
                node = node->next;
                dfs(node);
            }
        }else{
            Node* tempNode = node->next;
            node->next = node->child;
            node->child->prev = node;
            node->child = NULL;
            node = node->next;
            dfs(node);
            if(tempNode != NULL){
                node->next = tempNode;
                tempNode->prev = node;
                node = node->next;
                dfs(node);
            }
        }
    }
    
public:
    Node* flatten(Node* head) {
        Node* node = head;
        dfs(node);
        return head;
    }
};