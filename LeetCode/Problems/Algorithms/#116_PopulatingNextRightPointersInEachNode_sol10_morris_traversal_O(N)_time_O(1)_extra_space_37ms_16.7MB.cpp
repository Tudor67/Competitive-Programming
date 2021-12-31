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
    void updateNextPointers(Node* node){
        if(node != NULL && node->left != NULL){
            if(node->left != NULL){
                node->left->next = node->right;
            }
            if(node->right != NULL && node->next != NULL){
                node->right->next = node->next->left;
            }
        }
    }
    
public:
    Node* connect(Node* root) {
        Node* cur = root;
        while(cur != NULL){
            if(cur->left == NULL){
                updateNextPointers(cur);
                cur = cur->right;
            }else{
                Node* pred = cur->left;
                while(pred->right != NULL && pred->right != cur){
                    pred = pred->right;
                }
                if(pred->right == NULL){
                    updateNextPointers(cur);
                    pred->right = cur;
                    cur = cur->left;
                }else{
                    pred->right = NULL;
                    cur = cur->right;
                }
            }
        }
        return root;
    }
};