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
    void preorderTraversal(TreeNode* node, vector<TreeNode*>& preorderNodes){
        if(node != NULL){
            preorderNodes.push_back(node);
            preorderTraversal(node->left, preorderNodes);
            preorderTraversal(node->right, preorderNodes);
        }
    }
    
public:
    void flatten(TreeNode* root) {
        vector<TreeNode*> preorderNodes;
        preorderTraversal(root, preorderNodes);
        
        const int N = preorderNodes.size();
        for(int i = 0; i + 1 < N; ++i){
            preorderNodes[i]->left = NULL;
            preorderNodes[i]->right = preorderNodes[i + 1];
        }
    }
};