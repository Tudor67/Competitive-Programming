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
    vector<int> preorder(Node* root) {
        vector<int> answer;
        
        stack<Node*> st;
        if(root != NULL){
            st.push(root);
        }
        
        while(!st.empty()){
            Node* node = st.top();
            st.pop();
            
            answer.push_back(node->val);
            
            for(int j = (int)node->children.size() - 1; j >= 0; --j){
                if(node->children[j] != NULL){
                    st.push(node->children[j]);
                }
            }
        }
        
        return answer;
    }
};