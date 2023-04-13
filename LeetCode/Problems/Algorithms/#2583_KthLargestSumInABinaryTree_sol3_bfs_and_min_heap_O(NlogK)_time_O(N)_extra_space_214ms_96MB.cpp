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
        priority_queue<long long, vector<long long>, greater<long long>> minHeap;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            long long levelSum = 0;
            for(int i = q.size(); i >= 1; --i){
                TreeNode* node = q.front();
                q.pop();

                levelSum += node->val;

                if(node->left != nullptr){
                    q.push(node->left);
                }
                if(node->right != nullptr){
                    q.push(node->right);
                }
            }

            minHeap.push(levelSum);
            if((int)minHeap.size() == k + 1){
                minHeap.pop();
            }
        }

        if((int)minHeap.size() == k){
            return minHeap.top();
        }

        return -1;
    }
};