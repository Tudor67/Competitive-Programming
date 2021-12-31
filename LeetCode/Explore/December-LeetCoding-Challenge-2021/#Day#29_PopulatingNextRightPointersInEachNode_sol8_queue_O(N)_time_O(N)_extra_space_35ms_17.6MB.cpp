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
        q.push(root);
        
        while(!q.empty()){
            Node* node = q.front();
            q.pop();
            
            if(node == NULL){
                continue;
            }
            
            if(node->left != NULL){
                node->left->next = node->right;
            }
            if(node->right != NULL && node->next != NULL){
                node->right->next = node->next->left;
            }
            
            q.push(node->left);
            q.push(node->right);
        }
        
        return root;
    }
};