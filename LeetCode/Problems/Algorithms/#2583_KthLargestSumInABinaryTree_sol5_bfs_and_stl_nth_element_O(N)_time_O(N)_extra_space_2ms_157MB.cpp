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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        queue<TreeNode*> q;
        if(root != nullptr){
            q.push(root);
        }

        vector<long long> levelSums;
        while(!q.empty()){
            long long sum = 0;
            for(int i = (int)q.size(); i >= 1; --i){
                TreeNode* node = q.front();
                q.pop();

                sum += node->val;

                if(node->left != nullptr){
                    q.push(node->left);
                }
                if(node->right != nullptr){
                    q.push(node->right);
                }
            }

            levelSums.push_back(sum);
        }

        if((int)levelSums.size() >= k){
            nth_element(levelSums.begin(), levelSums.end() - k, levelSums.end());
            return levelSums[(int)levelSums.size() - k];
        }

        return -1;
    }
};