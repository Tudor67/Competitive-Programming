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
    void postOrderTraversal(Node* root, int level, vector<Node*>& st){
        if(root != NULL){
            postOrderTraversal(root->left, level + 1, st);
            postOrderTraversal(root->right, level + 1, st);
            if(st[level] != NULL){
                st[level]->next = root;
            }
            st[level] = root;
        }
    }
    
public:
    Node* connect(Node* root) {
        vector<Node*> st(12);
        postOrderTraversal(root, 0, st);
        return root;
    }
};