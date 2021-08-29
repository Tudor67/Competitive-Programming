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
class BSTIterator{
private:
    stack<TreeNode*> leftStack;
    stack<TreeNode*> rightStack;
    
public:
    BSTIterator(TreeNode* root){
        for(TreeNode* node = root; node != NULL; node = node->left){
            leftStack.push(node);
        }
        for(TreeNode* node = root; node != NULL; node = node->right){
            rightStack.push(node);
        }
    }
    
    TreeNode* nextLeftNode(){
        TreeNode* leftNode = leftStack.top(); leftStack.pop();
        for(TreeNode* node = leftNode->right; node != NULL; node = node->left){
            leftStack.push(node);
        }
        return leftNode;
    }
    
    TreeNode* nextRightNode(){
        TreeNode* rightNode = rightStack.top(); rightStack.pop();
        for(TreeNode* node = rightNode->left; node != NULL; node = node->right){
            rightStack.push(node);
        }
        return rightNode;
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        BSTIterator bstIt(root);
        TreeNode* leftNode = bstIt.nextLeftNode();
        TreeNode* rightNode = bstIt.nextRightNode();
        while(leftNode != rightNode){
            if(leftNode->val + rightNode->val < k){
                leftNode = bstIt.nextLeftNode();
            }else if(leftNode->val + rightNode->val > k){
                rightNode = bstIt.nextRightNode();
            }else{
                return true;
            }
        }
        return false;
    }
};