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
        Node* startNode = root;
        while(startNode != NULL){
            Node* prevChild = NULL;
            Node* firstChild = NULL;
            for(Node* node = startNode; node != NULL; node = node->next){
                for(Node* child: {node->left, node->right}){
                    if(child != NULL){
                        if(prevChild != NULL){
                            prevChild->next = child;
                        }else{
                            firstChild = child;
                        }
                        prevChild = child;
                    }
                }
            }
            startNode = firstChild;
        }
        return root;
    }
};