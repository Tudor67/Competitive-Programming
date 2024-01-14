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
    void collectLeafValues(TreeNode* node, vector<int>& leafValues){
        if(node != nullptr){
            if(node->left == nullptr && node->right == nullptr){
                leafValues.push_back(node->val);
            }else{
                collectLeafValues(node->left, leafValues);
                collectLeafValues(node->right, leafValues);
            }
        }
    }

public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leafValues1;
        collectLeafValues(root1, leafValues1);

        vector<int> leafValues2;
        collectLeafValues(root2, leafValues2);

        return (leafValues1 == leafValues2);
    }
};