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
    TreeNode* constructFromPrePost(vector<int>& preorder, int preStart, int preEnd,
                                   vector<int>& postorder, int postStart, int postEnd,
                                   vector<int>& postIndexOf){
        if(preStart > preEnd){
            return nullptr;
        }

        if(preStart == preEnd){
            return new TreeNode(preorder[preStart]);
        }
        
        TreeNode* root = new TreeNode(preorder[preStart]);
        int leftSize = postIndexOf[preorder[preStart + 1]] - postStart + 1;
        root->left = constructFromPrePost(preorder, preStart + 1, preStart + leftSize,
                                          postorder, postStart, postStart + leftSize - 1, postIndexOf);
        root->right = constructFromPrePost(preorder, preStart + leftSize + 1, preEnd,
                                           postorder, postStart + leftSize, postEnd - 1, postIndexOf);
        return root;
    }

public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        const int N = preorder.size();

        vector<int> postIndexOf(N + 1);
        for(int i = 0; i < N; ++i){
            postIndexOf[postorder[i]] = i;
        }

        return constructFromPrePost(preorder, 0, N - 1, postorder, 0, N - 1, postIndexOf);
    }
};