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
        Node* node = head;
        stack<Node*> st;
        while(node != NULL){            
            while(node->next != NULL && node->child == NULL){
                node = node->next;
            }
            if(node->child == NULL){
                if(!st.empty()){
                    node->next = st.top(); st.pop();
                    node->next->prev = node;
                }
                node = node->next;
            }else{
                if(node->next != NULL){
                    st.push(node->next);
                }
                node->next = node->child;
                node->child->prev = node;
                node->child = NULL;
                node = node->next;
            }
        }
        return head;
    }
};