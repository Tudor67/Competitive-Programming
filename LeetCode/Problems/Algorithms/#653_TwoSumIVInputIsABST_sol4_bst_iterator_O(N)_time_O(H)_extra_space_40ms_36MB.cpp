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
    TreeNode* leftNode;
    TreeNode* rightNode;
    
public:
    BSTIterator(TreeNode* root){
        for(TreeNode* node = root; node != NULL; node = node->left){
            leftStack.push(node);
        }
        for(TreeNode* node = root; node != NULL; node = node->right){
            rightStack.push(node);
        }
        leftNode = leftStack.top();
        rightNode = rightStack.top();
    }
    
    int nextLeftValue(){
        leftNode = leftStack.top(); leftStack.pop();
        for(TreeNode* node = leftNode->right; node != NULL; node = node->left){
            leftStack.push(node);
        }
        return leftNode->val;
    }
    
    int nextRightValue(){
        rightNode = rightStack.top(); rightStack.pop();
        for(TreeNode* node = rightNode->left; node != NULL; node = node->right){
            rightStack.push(node);
        }
        return rightNode->val;
    }
    
    bool sameLeftRightNode(){
        return (leftNode == rightNode);
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        BSTIterator bstIt(root);
        int leftValue = bstIt.nextLeftValue();
        int rightValue = bstIt.nextRightValue();
        while(!bstIt.sameLeftRightNode()){
            if(leftValue + rightValue < k){
                leftValue = bstIt.nextLeftValue();
            }else if(leftValue + rightValue > k){
                rightValue = bstIt.nextRightValue();
            }else{
                return true;
            }
        }
        return false;
    }
};