/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
private:
    unordered_map<Node*, Node*> node_copy;
    
public:
    Node* cloneGraph(Node* real_node) {
        if(node_copy.find(real_node) != node_copy.end()){
            return node_copy[real_node];
        }
        
        if(real_node == NULL){
            return NULL;
        }
        
        Node* node = new Node(real_node->val);
        node_copy[real_node] = node;
        for(Node* real_neighbor: real_node->neighbors){
            node->neighbors.push_back(cloneGraph(real_neighbor));
        }
        return node;
    }
};