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
    void dfs(TreeNode* parent, TreeNode* node, set<TreeNode*>& coveredNodes, int& answer){
        if(node != NULL){
            dfs(node, node->left, coveredNodes, answer);
            dfs(node, node->right, coveredNodes, answer);
            if(!coveredNodes.count(node->left) || !coveredNodes.count(node->right) || (parent == NULL && !coveredNodes.count(node))){
                coveredNodes.insert(node);
                coveredNodes.insert(parent);
                answer += 1;
            }
        }
    }
    
public:
    int minCameraCover(TreeNode* root) {
        set<TreeNode*> coveredNodes = {NULL};
        int answer = 0;
        dfs(NULL, root, coveredNodes, answer);
        return answer;
    }
};