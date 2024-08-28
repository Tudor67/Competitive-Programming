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
    void addLeftPath(Node* node, stack<pair<Node*, int>>& st){
        while(node != nullptr){
            st.push({node, 0});
            if(node->children.empty()){
                node = nullptr;
            }else{
                node = node->children[0];
            }
        }
    }

public:
    vector<int> postorder(Node* root) {
        vector<int> postorderValues;

        stack<pair<Node*, int>> st;
        if(root != nullptr){
            st.push({root, 0});
            if(!root->children.empty()){
                addLeftPath(root->children[0], st);
            }
        }

        while(!st.empty()){
            Node* node = st.top().first;
            int childID = st.top().second;

            if(childID + 1 < (int)node->children.size()){
                st.top().second = childID + 1;
                addLeftPath(node->children[childID + 1], st);
            }else{
                postorderValues.push_back(node->val);
                st.pop();
            }
        }

        return postorderValues;
    }
};