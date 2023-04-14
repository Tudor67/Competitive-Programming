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
        if(node == nullptr){
            copyOf[nullptr] = nullptr;
        }else if(!copyOf.count(node)){
            copyOf[node] = new Node(node->val);
            for(Node* neighbor: node->neighbors){
                copyOf[neighbor] = cloneGraph(neighbor, copyOf);
                copyOf[node]->neighbors.push_back(copyOf[neighbor]);
            }
        }
        return copyOf[node];
    }

public:
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> copyOf;
        return cloneGraph(node, copyOf);
    }
};