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
    void dfs(TreeNode* node, unordered_map<TreeNode*, int>& minCameras0, unordered_map<TreeNode*, int>& minCameras1){
        if(node == NULL){
            minCameras0[node] = 0;
            minCameras1[node] = 1;
        }else{
            dfs(node->left, minCameras0, minCameras1);
            dfs(node->right, minCameras0, minCameras1);
            
            // do not install a camera at `node`
            minCameras0[node] = min({minCameras0[node->left] + minCameras1[node->right],
                                     minCameras1[node->left] + minCameras0[node->right],
                                     minCameras1[node->left] + minCameras1[node->right]});
            
            // install a camera at `node`
            int leftMinCameras = min(minCameras0[node->left], minCameras1[node->left]);
            if(node->left != NULL){
                leftMinCameras = min(leftMinCameras, minCameras0[node->left->left] + minCameras0[node->left->right]);
            }
            int rightMinCameras = min(minCameras0[node->right], minCameras1[node->right]);
            if(node->right != NULL){
                rightMinCameras = min(rightMinCameras, minCameras0[node->right->left] + minCameras0[node->right->right]);
            }
            minCameras1[node] = 1 + leftMinCameras + rightMinCameras;
        }
    }
    
public:
    int minCameraCover(TreeNode* root) {
        // minCameras0[`node`]: min number of cameras to monitor the subtree with root == `node`
        //                      when we do not install a camera at `node`
        // minCameras1[`node`]: min number of cameras to monitor the subtree with root == `node`
        //                      when we install a camera at `node`
        unordered_map<TreeNode*, int> minCameras0;
        unordered_map<TreeNode*, int> minCameras1;
        dfs(root, minCameras0, minCameras1);
        return min(minCameras0[root], minCameras1[root]);
    }
};