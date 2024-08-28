/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
private:
    void postorder(Node* node, vector<int>& postorderValues){
        if(node == nullptr){
            return;
        }
        for(Node* child: node->children){
            postorder(child, postorderValues);
        }
        postorderValues.push_back(node->val);
    }

public:
    vector<int> postorder(Node* root) {
        vector<int> postorderValues;
        postorder(root, postorderValues);
        return postorderValues;
    }
};