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
        Node* parent = root;
        Node* firstChild;
        Node* prevChild;
        
        while(parent != NULL){
            firstChild = NULL;
            prevChild = NULL;
            for(; parent != NULL; parent = parent->next){
                for(Node* child: {parent->left, parent->right}){
                    if(child != NULL){
                        if(firstChild == NULL){
                            firstChild = child;
                            prevChild = child;
                        }else{
                            prevChild->next = child;
                            prevChild = child;
                        }
                    }
                }
            }
            parent = firstChild;
        }
        
        return root;
    }
};