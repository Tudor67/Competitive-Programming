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
    void inorderTraversal(TreeNode* root, vector<TreeNode*>& inorderNodes){
        if(root != NULL){
            inorderTraversal(root->left, inorderNodes);
            inorderNodes.push_back(root);
            inorderTraversal(root->right, inorderNodes);
        }
    }
    
    void inorderUpdate(TreeNode* root, const int& POS1, const int& VAL1, const int& POS2, const int& VAL2, int& idx){
        if(root != NULL){
            inorderUpdate(root->left, POS1, VAL1, POS2, VAL2, idx);
            if(idx == POS1){
                root->val = VAL2;
            }else if(idx == POS2){
                root->val = VAL1;
            }
            idx += 1;
            inorderUpdate(root->right, POS1, VAL1, POS2, VAL2, idx);
        }
    }
    
public:
    void recoverTree(TreeNode* root) {
        vector<TreeNode*> inorderNodes;
        inorderTraversal(root, inorderNodes);
        
        int pos1 = 0;
        for(int i = 0; i < (int)inorderNodes.size() - 1; ++i){
            if(inorderNodes[i]->val > inorderNodes[i + 1]->val){
                pos1 = i;
                break;
            }
        }
        
        int pos2 = 0;
        for(int i = (int)inorderNodes.size() - 2; i >= 0; --i){
            if(inorderNodes[i]->val > inorderNodes[i + 1]->val){
                pos2 = i + 1;
                break;
            }
        }
        
        int idx = 0;
        int val1 = inorderNodes[pos1]->val;
        int val2 = inorderNodes[pos2]->val;
        inorderUpdate(root, pos1, val1, pos2, val2, idx);
    }
};