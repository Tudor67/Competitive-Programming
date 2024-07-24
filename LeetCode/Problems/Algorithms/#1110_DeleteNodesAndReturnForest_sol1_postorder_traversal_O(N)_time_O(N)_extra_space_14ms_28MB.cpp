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
    void delNodes(TreeNode* node, unordered_set<int>& toDeleteSet, vector<TreeNode*>& forest){
        if(node == nullptr){
            return;
        }
        
        delNodes(node->left, toDeleteSet, forest);
        delNodes(node->right, toDeleteSet, forest);

        if(toDeleteSet.count(node->val) && node->left != nullptr && !toDeleteSet.count(node->left->val)){
            forest.push_back(node->left);
        }

        if(toDeleteSet.count(node->val) && node->right != nullptr && !toDeleteSet.count(node->right->val)){
            forest.push_back(node->right);
        }

        if(toDeleteSet.count(node->val)){
            node->left = nullptr;
            node->right = nullptr;
        }
        if(node->left != nullptr && toDeleteSet.count(node->left->val)){
            node->left = nullptr;
        }
        if(node->right != nullptr && toDeleteSet.count(node->right->val)){
            node->right = nullptr;
        }
    }

public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& toDelete) {
        unordered_set<int> toDeleteSet(toDelete.begin(), toDelete.end());

        vector<TreeNode*> forest;
        delNodes(root, toDeleteSet, forest);

        if(!toDeleteSet.count(root->val)){
            forest.push_back(root);
        }

        return forest;
    }
};