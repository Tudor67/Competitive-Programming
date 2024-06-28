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
    void inorder(TreeNode* node, vector<int>& sortedValues){
        if(node != nullptr){
            inorder(node->left, sortedValues);
            sortedValues.push_back(node->val);
            inorder(node->right, sortedValues);
        }
    }

    TreeNode* buildBST(int l, int r, vector<int>& sortedValues){
        if(l > r){
            return nullptr;
        }
        int mid = (l + r) / 2;
        return new TreeNode(sortedValues[mid],
                            buildBST(l, mid - 1, sortedValues),
                            buildBST(mid + 1, r, sortedValues));
    }

public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> sortedValues;
        inorder(root, sortedValues);

        return buildBST(0, (int)sortedValues.size() - 1, sortedValues);
    }
};