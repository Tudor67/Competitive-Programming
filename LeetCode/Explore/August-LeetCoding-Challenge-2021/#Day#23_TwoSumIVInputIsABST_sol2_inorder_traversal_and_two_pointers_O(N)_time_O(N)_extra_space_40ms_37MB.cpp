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
    void inorder(TreeNode* root, vector<int>& sortedValues){
        if(root != NULL){
            inorder(root->left, sortedValues);
            sortedValues.push_back(root->val);
            inorder(root->right, sortedValues);
        }
    }
    
public:
    bool findTarget(TreeNode* root, int k) {
        // dfs: inorder traversal of BST => sorted values of nodes
        vector<int> sortedValues;
        inorder(root, sortedValues);
        
        // two pointers approach to solve 2Sum problem in a sorted vector
        int i = 0;
        int j = (int)sortedValues.size() - 1;
        while(i < j){
            if(sortedValues[i] + sortedValues[j] < k){
                i += 1;
            }else if(sortedValues[i] + sortedValues[j] > k){
                j -= 1;
            }else{
                return true;
            }
        }
        
        return false;
    }
};