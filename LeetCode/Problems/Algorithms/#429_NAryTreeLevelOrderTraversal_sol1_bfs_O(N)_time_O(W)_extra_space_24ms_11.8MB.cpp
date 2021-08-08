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
        vector<vector<int>> levels;
        
        queue<pair<Node*, int>> q;
        if(root != NULL){
            levels = {{root->val}};
            q.push({root, 0});
        }
        
        while(!q.empty()){
            Node* node = q.front().first;
            int level = q.front().second;
            q.pop();
            
            for(Node* child: node->children){
                if(level + 1 == (int)levels.size()){
                    levels.push_back({});
                }
                levels[level + 1].push_back(child->val);
                q.push({child, level + 1});
            }
        }
        
        return levels;
    }
};