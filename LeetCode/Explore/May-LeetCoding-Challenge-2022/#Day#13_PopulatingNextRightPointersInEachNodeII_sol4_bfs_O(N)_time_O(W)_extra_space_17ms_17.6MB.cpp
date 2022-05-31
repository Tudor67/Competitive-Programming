/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> q;
        if(root != NULL){
            q.push(root);
        }
        
        while(!q.empty()){
            Node* prevNode = NULL;
            for(int i = (int)q.size(); i >= 1; --i){
                Node* node = q.front();
                q.pop();
                
                if(prevNode != NULL){
                    prevNode->next = node;
                }
                prevNode = node;
                
                for(Node* child: {node->left, node->right}){
                    if(child != NULL){
                        q.push(child);
                    }
                }
            }
        }
        
        return root;
    }
};