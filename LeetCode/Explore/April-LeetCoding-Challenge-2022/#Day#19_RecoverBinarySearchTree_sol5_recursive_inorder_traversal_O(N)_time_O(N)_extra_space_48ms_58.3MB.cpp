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
    void inorder(TreeNode* node, vector<TreeNode*>& inorderNodes){
        if(node != NULL){
            inorder(node->left, inorderNodes);
            inorderNodes.push_back(node);
            inorder(node->right, inorderNodes);
        }
    }
    
public:
    void recoverTree(TreeNode* root) {
        vector<TreeNode*> inorderNodes;
        inorder(root, inorderNodes);
        
        TreeNode* node1 = NULL;
        TreeNode* node2 = NULL;
        
        const int N = inorderNodes.size();
        for(int i = 0; i + 1 < N; ++i){
            if(inorderNodes[i]->val > inorderNodes[i + 1]->val){
                if(node1 == NULL){
                    node1 = inorderNodes[i];
                }
                node2 = inorderNodes[i + 1];
            }
        }
        
        swap(node1->val, node2->val);
    }
};