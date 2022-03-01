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
public:
    Node* cloneGraph(Node* startNode) {
        if(startNode == NULL){
            return NULL;
        }
        
        queue<Node*> q;
        q.push(startNode);
        unordered_map<Node*, Node*> copyOf;
        copyOf[startNode] = new Node(startNode->val);
        
        while(!q.empty()){
            Node* node = q.front();
            q.pop();
            
            for(Node* nextNode: node->neighbors){
                if(!copyOf.count(nextNode)){
                    copyOf[nextNode] = new Node(nextNode->val);
                    q.push(nextNode);
                }
                copyOf[node]->neighbors.push_back(copyOf[nextNode]);
            }
        }
        
        return copyOf[startNode];
    }
};