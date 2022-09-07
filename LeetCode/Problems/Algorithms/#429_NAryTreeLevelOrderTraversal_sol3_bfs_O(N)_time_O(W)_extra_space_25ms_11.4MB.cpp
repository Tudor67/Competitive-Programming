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
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        
        queue<Node*> q;
        if(root != nullptr){
            q.push(root);
        }
        
        while(!q.empty()){
            res.push_back({});
            res.back().reserve(q.size());
            for(int i = q.size(); i >= 1; --i){
                Node* node = q.front();
                q.pop();
                
                res.back().push_back(node->val);
                
                for(Node* child: node->children){
                    q.push(child);
                }
            }
        }
        
        return res;
    }
};