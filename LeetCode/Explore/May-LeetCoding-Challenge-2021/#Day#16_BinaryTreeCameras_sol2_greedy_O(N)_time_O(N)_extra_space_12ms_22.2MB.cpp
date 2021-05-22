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
    void dfs(TreeNode* parent, TreeNode* node, set<TreeNode*>& nodesWithCamera){
        if(node != NULL){
            dfs(node, node->left, nodesWithCamera);
            dfs(node, node->right, nodesWithCamera);
            if(!nodesWithCamera.count(node) && !nodesWithCamera.count(node->left) && !nodesWithCamera.count(node->right)){
                if(parent == NULL){
                    nodesWithCamera.insert(node);
                }else if(!nodesWithCamera.count(parent)){
                    nodesWithCamera.insert(parent);
                }
            }
        }
    }
    
public:
    int minCameraCover(TreeNode* root) {
        set<TreeNode*> nodesWithCamera;
        dfs(NULL, root, nodesWithCamera);
        return nodesWithCamera.size();
    }
};