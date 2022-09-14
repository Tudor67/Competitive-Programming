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
    void updateResult(int parityMask, int& res){
        int paritySum = __builtin_popcount((unsigned int)parityMask);
        res += (int)(paritySum <= 1);
    }
    
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        int res = 0;
        
        int parityMask = 0;
        TreeNode* currentNode = root;
        while(currentNode != nullptr){
            if(currentNode->left == nullptr){
                parityMask ^= (1 << currentNode->val);
                if(currentNode->right == nullptr){
                    updateResult(parityMask, res);
                }
                currentNode = currentNode->right;
            }else{
                TreeNode* pred = currentNode->left;
                int paritySubmask = (1 << pred->val);
                while(pred->right != nullptr && pred->right != currentNode){
                    paritySubmask ^= (1 << pred->right->val);
                    pred = pred->right;
                }
                
                if(pred->right == nullptr){
                    parityMask ^= (1 << currentNode->val);
                    pred->right = currentNode;
                    currentNode = currentNode->left;
                }else{
                    if(pred->left == nullptr){
                        updateResult(parityMask, res);
                    }
                    parityMask ^= paritySubmask;
                    pred->right = nullptr;
                    currentNode = currentNode->right;
                }
            }
        }
        
        return res;
    }
};