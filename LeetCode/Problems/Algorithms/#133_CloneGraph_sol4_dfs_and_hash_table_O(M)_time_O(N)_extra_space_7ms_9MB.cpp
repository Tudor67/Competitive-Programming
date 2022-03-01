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
    Node* cloneGraph(Node* node, unordered_map<Node*, Node*>& copyOf){
        if(copyOf.count(node)){
            return copyOf[node];
        }
        copyOf[node] = new Node(node->val);
        for(Node* nextNode: node->neighbors){
            copyOf[node]->neighbors.push_back(cloneGraph(nextNode, copyOf));
        }
        return copyOf[node];
    }
    
public:
    Node* cloneGraph(Node* node) {
        if(node == NULL){
            return NULL;
        }
        unordered_map<Node*, Node*> copyOf;
        return cloneGraph(node, copyOf);
    }
};