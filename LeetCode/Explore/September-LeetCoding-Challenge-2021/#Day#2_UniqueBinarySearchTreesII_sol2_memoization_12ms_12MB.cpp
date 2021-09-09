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
    vector<TreeNode*> generateTrees(int rootStartValue, int rootEndValue, vector<vector<vector<TreeNode*>>>& memo){
        if(rootStartValue > rootEndValue){
            return {NULL};
        }
        if(!memo[rootStartValue][rootEndValue].empty()){
            return memo[rootStartValue][rootEndValue];
        }
        vector<TreeNode*> trees;
        for(int rootValue = rootStartValue; rootValue <= rootEndValue; ++rootValue){
            vector<TreeNode*> leftTrees = generateTrees(rootStartValue, rootValue - 1, memo);
            vector<TreeNode*> rightTrees = generateTrees(rootValue + 1, rootEndValue, memo);
            for(TreeNode* leftTree: leftTrees){
                for(TreeNode* rightTree: rightTrees){
                    TreeNode* root = new TreeNode(rootValue);
                    root->left = leftTree;
                    root->right = rightTree;
                    trees.push_back(root);
                }
            }
        }
        memo[rootStartValue][rootEndValue] = trees;
        return trees;
    }
    
public:
    vector<TreeNode*> generateTrees(int n) {
        vector<vector<vector<TreeNode*>>> memo(n + 1, vector<vector<TreeNode*>>(n + 1));
        return generateTrees(1, n, memo);
    }
};