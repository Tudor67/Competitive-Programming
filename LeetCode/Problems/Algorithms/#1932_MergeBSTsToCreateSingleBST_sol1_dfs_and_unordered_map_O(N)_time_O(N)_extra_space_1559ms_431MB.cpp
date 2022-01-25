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
    void mergeBST(TreeNode* root, unordered_map<int, TreeNode*>& rootFor, int& mergeOperations){
        if(root == NULL){
            return;
        }
        if(root->left != NULL && rootFor.count(root->left->val)){
            root->left = rootFor[root->left->val];
            rootFor.erase(root->left->val);
            mergeOperations += 1;
        }
        if(root->right != NULL && rootFor.count(root->right->val)){
            root->right = rootFor[root->right->val];
            rootFor.erase(root->right->val);
            mergeOperations += 1;
        }
        mergeBST(root->left, rootFor, mergeOperations);
        mergeBST(root->right, rootFor, mergeOperations);
    }
    
    bool isBST(TreeNode* root, int minVal, int maxVal){
        if(root == NULL){
            return true;
        }
        return (minVal <= root->val && root->val <= maxVal) &&
               isBST(root->left, minVal, root->val - 1) &&
               isBST(root->right, root->val + 1, maxVal);
    }
    
public:
    TreeNode* canMerge(vector<TreeNode*>& trees) {
        const int N = trees.size();
        
        // Step 1: count all children values
        //         if we have duplicate values among children => we cannot satisfy the properties of BSTs
        //         also, store (root->val, root) map for fast access of roots in mergeBST(..)
        unordered_map<int, TreeNode*> rootFor;
        unordered_map<int, int> childCount;
        for(TreeNode* root: trees){
            rootFor[root->val] = root;
            for(TreeNode* child: {root->left, root->right}){
                if(child != NULL){
                    childCount[child->val] += 1;
                    if(childCount[child->val] >= 2){
                        return NULL;
                    }
                }
            }
        }
        
        // Step 2: fix the global root for the final tree
        //         the global root cannot be the child of any node
        //         the global root should be unique
        //         if we have zero or more than one global root => we cannot merge all trees
        TreeNode* globalRoot = NULL;
        for(TreeNode* root: trees){
            if(!childCount.count(root->val)){
                if(globalRoot == NULL){
                    globalRoot = root;
                }else{
                    return NULL;
                }
            }
        }
        
        // Step 3: save original children of each trees[i]
        //         we need this for Step 6
        unordered_map<TreeNode*, pair<TreeNode*, TreeNode*>> originalLeftRightChildrenOf;
        for(TreeNode* root: trees){
            originalLeftRightChildrenOf[root] = {root->left, root->right};
        }
        
        // Step 4: merge trees
        int mergeOperations = 0;
        mergeBST(globalRoot, rootFor, mergeOperations);
        
        // Step 5: check if we merged all trees
        //         check if the final tree is a valid BST
        //         if merge is ok then return global root of the final BST
        //                        else go to Step 6 
        if(mergeOperations == N - 1 && isBST(globalRoot, 0, INT_MAX)){
            return globalRoot;
        }
        
        // Step 6: undo mergeBST and return NULL
        for(TreeNode* root: trees){
            root->left = originalLeftRightChildrenOf[root].first;
            root->right = originalLeftRightChildrenOf[root].second;
        }
        
        return NULL;
    }
};