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
    void dfs(Node* node, int level, vector<vector<int>>& levels){
        if(node != NULL){
            if(level == (int)levels.size()){
                levels.push_back({});
            }
            levels[level].push_back(node->val);
            for(Node* child: node->children){
                dfs(child, level + 1, levels);
            }
        }
    }
    
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> levels;
        dfs(root, 0, levels);
        return levels;
    }
};