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
public:
    int maxLevelSum(TreeNode* root) {
        int maxSum = root->val;
        int maxSumLevel = 1;

        queue<TreeNode*> q;
        q.push(root);

        int currLevel = 1;
        while(!q.empty()){
            int currSum = 0;
            
            for(int i = q.size(); i >= 1; --i){
                TreeNode* currNode = q.front();
                q.pop();

                currSum += currNode->val;

                if(currNode->left != nullptr){
                    q.push(currNode->left);
                }
                if(currNode->right != nullptr){
                    q.push(currNode->right);
                }
            }

            if(maxSum < currSum){
                maxSum = currSum;
                maxSumLevel = currLevel;
            }
            
            currLevel += 1;
        }

        return maxSumLevel;
    }
};