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
    void rec(Node* root, int level, int& completedLevels){
        if(root == NULL){
            return;
        }
        
        if(level > completedLevels){
            Node* prev = NULL;
            for(Node* node = root; node != NULL; node = node->next){
                for(Node* child: {node->left, node->right}){
                    if(child != NULL){
                        if(prev == NULL){
                            prev = child;
                        }else{
                            prev->next = child;
                            prev = child;
                        }
                    }
                }
            }
            completedLevels = level;
        }
        
        rec(root->left, level + 1, completedLevels);
        rec(root->right, level + 1, completedLevels);
    }
    
public:
    Node* connect(Node* root) {
        int completedLevels = 0;
        rec(root, 1, completedLevels);
        return root;
    }
};