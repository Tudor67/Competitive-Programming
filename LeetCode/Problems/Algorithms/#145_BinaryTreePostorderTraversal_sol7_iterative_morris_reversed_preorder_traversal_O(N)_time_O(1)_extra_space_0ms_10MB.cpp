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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> postorderValues;

        TreeNode* currNode = root;
        while(currNode != nullptr){
            if(currNode->right == nullptr){
                postorderValues.push_back(currNode->val);
                currNode = currNode->left;
            }else{
                TreeNode* succNode = currNode->right;
                while(succNode->left != nullptr && succNode->left != currNode){
                    succNode = succNode->left;
                }

                if(succNode->left == nullptr){
                    postorderValues.push_back(currNode->val);
                    succNode->left = currNode;
                    currNode = currNode->right;
                }else{
                    succNode->left = nullptr;
                    currNode = currNode->left;
                }
            }
        }

        reverse(postorderValues.begin(), postorderValues.end());

        return postorderValues;
    }
};