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
    void delNodes(TreeNode* parent, TreeNode* node, unordered_set<int>& toDeleteSet, vector<TreeNode*>& forest){
        if(node == nullptr){
            return;
        }
        
        delNodes(node, node->left, toDeleteSet, forest);
        delNodes(node, node->right, toDeleteSet, forest);

        if(!toDeleteSet.count(node->val) && (parent == nullptr || toDeleteSet.count(parent->val))){
            forest.push_back(node);
        }

        if(toDeleteSet.count(node->val)){
            node->left = nullptr;
            node->right = nullptr;
            if(parent != nullptr && parent->left == node){
                parent->left = nullptr;
            }
            if(parent != nullptr && parent->right == node){
                parent->right = nullptr;
            }
        }
    }

public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& toDelete) {
        unordered_set<int> toDeleteSet(toDelete.begin(), toDelete.end());

        vector<TreeNode*> forest;
        delNodes(nullptr, root, toDeleteSet, forest);

        return forest;
    }
};