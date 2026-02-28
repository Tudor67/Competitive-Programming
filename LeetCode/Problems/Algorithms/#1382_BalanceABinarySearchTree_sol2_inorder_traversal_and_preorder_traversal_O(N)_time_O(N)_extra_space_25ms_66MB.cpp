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
    void inorder(const TreeNode* root, vector<int>& sortedValues){
        if(root == nullptr){
            return;
        }
        inorder(root->left, sortedValues);
        sortedValues.push_back(root->val);
        inorder(root->right, sortedValues);
    }

    TreeNode* buildBalancedBST(vector<int>& sortedValues, int l, int r){
        if(l > r){
            return nullptr;
        }
        int mid = (l + r) / 2;
        TreeNode* root = new TreeNode(sortedValues[mid]);
        root->left = buildBalancedBST(sortedValues, l, mid - 1);
        root->right = buildBalancedBST(sortedValues, mid + 1, r);
        return root;
    }

public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> sortedValues;
        inorder(root, sortedValues);

        return buildBalancedBST(sortedValues, 0, (int)sortedValues.size() - 1);
    }
};