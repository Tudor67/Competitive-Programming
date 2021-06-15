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
    TreeNode* buildTree(vector<int>& preorder, int& preorderIdx,
                        vector<int>& inorder, int inorderLeftIdx, int inorderRightIdx, unordered_map<int, int>& inorderIdxOf){
        if(inorderLeftIdx > inorderRightIdx){
            return NULL;
        }
        int rootVal = preorder[preorderIdx];
        int rootIdx = inorderIdxOf[rootVal];
        TreeNode* root = new TreeNode(rootVal);
        preorderIdx += 1;
        root->left = buildTree(preorder, preorderIdx, inorder, inorderLeftIdx, rootIdx - 1, inorderIdxOf);
        root->right = buildTree(preorder, preorderIdx, inorder, rootIdx + 1, inorderRightIdx, inorderIdxOf);
        return root;
    }
    
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        const int N = inorder.size();
        int preorderIdx = 0;
        int inorderLeftIdx = 0;
        int inorderRightIdx = N - 1;
        unordered_map<int, int> inorderIdxOf;
        for(int i = 0; i < N; ++i){
            inorderIdxOf[inorder[i]] = i;
        }
        return buildTree(preorder, preorderIdx, inorder, inorderLeftIdx, inorderRightIdx, inorderIdxOf);
    }
};