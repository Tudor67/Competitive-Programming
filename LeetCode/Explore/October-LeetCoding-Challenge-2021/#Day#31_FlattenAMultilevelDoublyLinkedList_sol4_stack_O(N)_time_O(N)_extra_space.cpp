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
        if(head == NULL){
            return NULL;
        }
        
        Node* prevHead = new Node(0, NULL, head, NULL);
        Node* prevNode = prevHead;
        
        stack<Node*> st;
        st.push(head);
        while(!st.empty()){
            Node* node = st.top(); st.pop();
            if(node->next != NULL){
                st.push(node->next);
            }
            if(node->child != NULL){
                st.push(node->child);
            }
            prevNode->next = node;
            node->prev = prevNode;
            node->child = NULL;
            prevNode = node;
        }
        
        prevHead->next = NULL;
        head->prev = NULL;
        delete prevHead;
        
        return head;
    }
};