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
public:
    vector<int> postorder(Node* root) {
        vector<int> postorderValues;

        Node* postorderPrevNode = nullptr;
        stack<Node*> st;
        if(root != nullptr){
            st.push(root);
        }

        while(!st.empty()){
            Node* node = st.top();

            if(node->children.empty() || node->children.back() == postorderPrevNode){
                postorderValues.push_back(node->val);
                postorderPrevNode = node;
                st.pop();
            }else{
                for(int i = (int)node->children.size() - 1; i >= 0; --i){
                    st.push(node->children[i]);
                }
            }
        }

        return postorderValues;
    }
};