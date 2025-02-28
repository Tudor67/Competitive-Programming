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
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        const int N = preorder.size();

        // Special cases
        if(N == 0){
            return nullptr;
        }

        if(N == 1){
            return new TreeNode(preorder[0]);
        }

        // Fix root, find left and right subtree values
        int leftSize = find(postorder.begin(), postorder.end(), preorder[1])
                       - postorder.begin() + 1;

        vector<int> leftPreorder, leftPostorder;
        vector<int> rightPreorder, rightPostorder;
        for(int i = 1; i < N; ++i){
            if(i <= leftSize){
                leftPreorder.push_back(preorder[i]);
                leftPostorder.push_back(postorder[i - 1]);
            }else{
                rightPreorder.push_back(preorder[i]);
                rightPostorder.push_back(postorder[i - 1]);
            }
        }
        
        TreeNode* root = new TreeNode(preorder.front());
        root->left = constructFromPrePost(leftPreorder, leftPostorder);
        root->right = constructFromPrePost(rightPreorder, rightPostorder);

        return root;
    }
};