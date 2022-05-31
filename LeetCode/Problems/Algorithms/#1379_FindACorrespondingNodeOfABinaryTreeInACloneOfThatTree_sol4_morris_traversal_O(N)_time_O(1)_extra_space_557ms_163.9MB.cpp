/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class TreeIterator{
private:
    TreeNode* curr;
    TreeNode* pred;
    TreeNode* it;
    
public:
    TreeIterator(TreeNode* root){
        curr = root;
    }
    
    TreeNode* next(){
        it = NULL;
        while(it == NULL && curr != NULL){
            if(curr->left == NULL){
                it = curr;
                curr = curr->right;
            }else{
                pred = curr->left;
                while(pred->right != NULL && pred->right != curr){
                    pred = pred->right;
                }
                if(pred->right == NULL){
                    it = curr;
                    pred->right = curr;
                    curr = curr->left;
                }else{
                    pred->right = NULL;
                    curr = curr->right;
                }
            }
        }
        return it;
    }
    
    bool hasNext(){
        return (curr != NULL);
    }
};

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        TreeNode* res = NULL;
        TreeIterator originalIt(original);
        TreeIterator clonedIt(cloned);
        while(originalIt.hasNext()){
            TreeNode* originalCurrentNode = originalIt.next();
            TreeNode* clonedCurrentNode = clonedIt.next();
            if(originalCurrentNode == target){
                res = clonedCurrentNode;
            }
        }
        return res;
    }
};