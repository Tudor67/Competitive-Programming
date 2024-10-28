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

        priority_queue<long long, vector<long long>, greater<long long>> minHeap;
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

            minHeap.push(sum);
            if((int)minHeap.size() > k){
                minHeap.pop();
            }
        }

        if((int)minHeap.size() == k){
            return minHeap.top();
        }

        return -1;
    }
};