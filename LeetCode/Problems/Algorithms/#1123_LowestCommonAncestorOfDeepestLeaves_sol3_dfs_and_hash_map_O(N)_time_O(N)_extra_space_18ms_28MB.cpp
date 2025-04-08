/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    void dfs(int level, TreeNode* parent, TreeNode* node,
             unordered_map<TreeNode*, TreeNode*>& parentOf,
             unordered_map<TreeNode*, int>& levelOf){
        if(node == nullptr){
            return;
        }
        parentOf[node] = parent;
        levelOf[node] = level;
        dfs(level + 1, node, node->left, parentOf, levelOf);
        dfs(level + 1, node, node->right, parentOf, levelOf);
    }

public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        unordered_map<TreeNode*, TreeNode*> parentOf;
        unordered_map<TreeNode*, int> levelOf;
        dfs(0, nullptr, root, parentOf, levelOf);

        int maxLevel = -1;
        unordered_set<TreeNode*> currNodes;
        for(auto& [node, level]: levelOf){
            if(maxLevel < level){
                maxLevel = level;
                currNodes.clear();
                currNodes.insert(node);
            }else if(maxLevel == level){
                currNodes.insert(node);
            }
        }

        unordered_set<TreeNode*> nextNodes;
        while((int)currNodes.size() >= 2){
            nextNodes.clear();
            for(TreeNode* node: currNodes){
                nextNodes.insert(parentOf[node]);
            }
            currNodes.swap(nextNodes);
        }

        return *currNodes.begin();
    }
};