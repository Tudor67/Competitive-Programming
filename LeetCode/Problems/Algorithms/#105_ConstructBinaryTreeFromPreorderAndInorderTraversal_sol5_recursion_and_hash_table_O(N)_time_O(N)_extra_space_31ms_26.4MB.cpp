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
                        vector<int>& inorder, int inorderLeftIdx, int inorderRightIdx,
                        unordered_map<int, int>& inorderIdxOf) {
        if(inorderLeftIdx > inorderRightIdx){
            return NULL;
        }
        
        int rootVal = preorder[preorderIdx];
        preorderIdx += 1;
        
        int inorderRootIdx = inorderIdxOf[rootVal];
        
        TreeNode* root = new TreeNode(rootVal);
        root->left = buildTree(preorder, preorderIdx, inorder, inorderLeftIdx, inorderRootIdx - 1, inorderIdxOf);
        root->right = buildTree(preorder, preorderIdx, inorder, inorderRootIdx + 1, inorderRightIdx, inorderIdxOf);
        
        return root;
    }
    
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        const int N = preorder.size();
        
        unordered_map<int, int> inorderIdxOf;
        for(int i = 0; i < N; ++i){
            inorderIdxOf[inorder[i]] = i;
        }
        
        int preorderIdx = 0;
        return buildTree(preorder, preorderIdx, inorder, 0, N - 1, inorderIdxOf);
    }
};