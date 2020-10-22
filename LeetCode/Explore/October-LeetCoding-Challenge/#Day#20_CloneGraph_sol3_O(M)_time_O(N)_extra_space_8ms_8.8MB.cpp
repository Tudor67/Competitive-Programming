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
    unordered_map<Node*, Node*> copyOf;
    
public:
    Node* cloneGraph(Node* node) {
        if(node == NULL){
            return NULL;
        }
        if(!copyOf.count(node)){
            copyOf[node] = new Node(node->val);
            for(Node* neighbor: node->neighbors){
                copyOf[node]->neighbors.push_back(cloneGraph(neighbor));
            }
        }
        return copyOf[node];
    }
};