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
    void dfs(Node* root, vector<int>& answer){
        if(root != NULL){
            answer.push_back(root->val);
            for(Node* child: root->children){
                dfs(child, answer);
            }
        }
    }
    
public:
    vector<int> preorder(Node* root) {
        vector<int> answer;
        dfs(root, answer);
        return answer;
    }
};