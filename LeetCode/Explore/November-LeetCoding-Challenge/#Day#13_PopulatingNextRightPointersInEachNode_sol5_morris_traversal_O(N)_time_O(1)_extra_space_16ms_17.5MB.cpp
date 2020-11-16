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
    void connectLeftRightPaths(Node* leftNode, Node* rightNode){
        while(leftNode != NULL){
            leftNode->next = rightNode;
            leftNode = leftNode->right;
            rightNode = rightNode->left;
        }
    }
    
public:
    Node* connect(Node* root) {
        if(root == NULL || root->left == NULL){
            return root;
        }
        
        Node* cur = root;
        Node* pred = NULL;
        while(cur->right != NULL){
            connectLeftRightPaths(cur->left, cur->right);
            if(cur->left == NULL){
                pred = cur;
                cur = cur->right->right;
                pred->right = NULL;
            }else{
                pred = cur->left;
                while(pred->right != NULL){
                    pred = pred->right;
                }
                pred->right = cur;
                cur = cur->left;
            }
        }
        
        return root;
    }
};