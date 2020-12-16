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
    int getMaxDepth(int depth, TreeNode* root, int& globalMaxDepth, TreeNode*& answer){
        if(root == NULL){
            return depth;
        }
        int leftMaxDepth = getMaxDepth(depth + 1, root->left, globalMaxDepth, answer);
        int rightMaxDepth = getMaxDepth(depth + 1, root->right, globalMaxDepth, answer);
        globalMaxDepth = max({leftMaxDepth, rightMaxDepth, globalMaxDepth});
        if(leftMaxDepth == rightMaxDepth && rightMaxDepth == globalMaxDepth){
            answer = root;
        }
        return max(leftMaxDepth, rightMaxDepth);
    }
    
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        TreeNode* answer = NULL;
        int globalMaxDepth = 0;
        getMaxDepth(0, root, globalMaxDepth, answer);
        return answer;
    }
};