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
        for(Node* startNode = root; startNode != NULL; startNode = startNode->left){
            for(Node* node = startNode; node != NULL; node = node->next){
                if(node->left != NULL){
                    node->left->next = node->right;
                }
                if(node->right != NULL && node->next != NULL){
                    node->right->next = node->next->left;
                }
            }
        }
        return root;
    }
};