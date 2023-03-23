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
    TreeNode* buildTree(vector<int>& inorder, int inorderFirstIndex, int inorderLastIndex,
                        vector<int>& postorder, int postorderFirstIndex, int postorderLastIndex,
                        unordered_map<int, int>& inorderIndexOf) {
        if(inorderFirstIndex > inorderLastIndex){
            return nullptr;
        }
        
        int rootVal = postorder[postorderLastIndex];
        int rootInorderIndex = inorderIndexOf[rootVal];
        int leftSubtreeSize = rootInorderIndex - inorderFirstIndex;
        int rightSubtreeSize = inorderLastIndex - rootInorderIndex;

        TreeNode* root = new TreeNode(rootVal);
        root->left = buildTree(inorder, inorderFirstIndex, inorderFirstIndex + leftSubtreeSize - 1,
                               postorder, postorderFirstIndex, postorderFirstIndex + leftSubtreeSize - 1,
                               inorderIndexOf);
        root->right = buildTree(inorder, inorderLastIndex - rightSubtreeSize + 1, inorderLastIndex,
                                postorder, postorderLastIndex - rightSubtreeSize, postorderLastIndex - 1,
                                inorderIndexOf);

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        const int N = inorder.size();

        unordered_map<int, int> inorderIndexOf;
        for(int i = 0; i < N; ++i){
            inorderIndexOf[inorder[i]] = i;
        }

        return buildTree(inorder, 0, N - 1, postorder, 0, N - 1, inorderIndexOf);
    }
};