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
private:
    void dfs(int level, Node* node, vector<Node*>& prevNodeAt){
        if(node == NULL){
            return;
        }
        
        if(level == (int)prevNodeAt.size()){
            prevNodeAt.push_back(NULL);
        }
        
        if(prevNodeAt[level] != NULL){
            prevNodeAt[level]->next = node;
        }
        prevNodeAt[level] = node;
        
        dfs(level + 1, node->left, prevNodeAt);
        dfs(level + 1, node->right, prevNodeAt);
    }
    
public:
    Node* connect(Node* root) {
        vector<Node*> prevNodeAt;
        dfs(0, root, prevNodeAt);
        return root;
    }
};