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
    void inorder(TreeNode* node, int& val, int& valCount, int& maxCount, vector<int>& modes){
        if(node != nullptr){
            inorder(node->left, val, valCount, maxCount, modes);
            
            if(val == node->val){
                valCount += 1;
            }else{
                val = node->val;
                valCount = 1;
            }

            if(valCount > maxCount){
                maxCount = valCount;
                modes.clear();
                modes.push_back(val);
            }else if(valCount == maxCount){
                if(modes.empty() || modes.back() != val){
                    modes.push_back(val);
                }
            }

            inorder(node->right, val, valCount, maxCount, modes);
        }
    }

public:
    vector<int> findMode(TreeNode* root) {
        int val = INT_MIN;
        int valCount = 0;
        int maxCount = 0;
        vector<int> modes;

        inorder(root, val, valCount, maxCount, modes);

        return modes;
    }
};