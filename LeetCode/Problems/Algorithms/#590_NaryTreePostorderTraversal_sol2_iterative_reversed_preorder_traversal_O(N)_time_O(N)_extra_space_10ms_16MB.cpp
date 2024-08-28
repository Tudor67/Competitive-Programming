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

        stack<Node*> st;
        if(root != nullptr){
            st.push(root);
        }

        while(!st.empty()){
            Node* node = st.top();
            st.pop();

            postorderValues.push_back(node->val);

            for(Node* child: node->children){
                st.push(child);
            }
        }

        reverse(postorderValues.begin(), postorderValues.end());

        return postorderValues;
    }
};