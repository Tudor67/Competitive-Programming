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
    TreeNode* reverseOddLevels(TreeNode* root) {
        deque<TreeNode*> dq;
        dq.push_back(root);
        
        int level = 0;
        while(!dq.empty()){
            if(level % 2 == 1){
                deque<TreeNode*> dqCopy = dq;
                while(dqCopy.size() >= 2){
                    TreeNode* frontNode = dqCopy.front();
                    TreeNode* backNode = dqCopy.back();
                    dqCopy.pop_front();
                    dqCopy.pop_back();
                    swap(frontNode->val, backNode->val);
                }
            }
            
            for(int i = dq.size(); i >= 1; --i){
                TreeNode* node = dq.front();
                dq.pop_front();
                
                if(node->left != nullptr){
                    dq.push_back(node->left);
                }
                if(node->right != nullptr){
                    dq.push_back(node->right);
                }
            }
            
            level += 1;
        }
        
        return root;
    }
};