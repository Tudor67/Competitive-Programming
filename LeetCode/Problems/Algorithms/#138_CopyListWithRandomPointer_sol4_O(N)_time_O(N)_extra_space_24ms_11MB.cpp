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
        unordered_map<Node*, Node*> copyOf;
        
        copyOf[NULL] = NULL;
        for(Node* node = head; node != NULL; node = node->next){
            copyOf[node] = new Node(node->val);
        }
        
        for(Node* node = head; node != NULL; node = node->next){
            copyOf[node]->next = copyOf[node->next];
            copyOf[node]->random = copyOf[node->random];
        }
        
        return copyOf[head];
    }
};