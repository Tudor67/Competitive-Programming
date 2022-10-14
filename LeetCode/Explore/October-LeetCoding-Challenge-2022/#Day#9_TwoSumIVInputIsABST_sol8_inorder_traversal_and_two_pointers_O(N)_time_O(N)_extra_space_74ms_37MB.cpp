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
        if(root != nullptr){
            inorder(root->left, sortedValues);
            sortedValues.push_back(root->val);
            inorder(root->right, sortedValues);
        }
    }
    
public:
    bool findTarget(TreeNode* root, int k) {
        vector<int> sortedValues;
        inorder(root, sortedValues);
        
        int i = 0;
        int j = (int)sortedValues.size() - 1;
        while(i < j){
            int sum = sortedValues[i] + sortedValues[j];
            if(sum < k){
                i += 1;
            }else if(sum > k){
                j -= 1;
            }else{
                return true;
            }
        }
        
        return false;
    }
};