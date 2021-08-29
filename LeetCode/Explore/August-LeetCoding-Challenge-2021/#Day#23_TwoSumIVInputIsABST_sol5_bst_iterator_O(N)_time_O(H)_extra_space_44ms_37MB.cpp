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
    stack<TreeNode*> st;
    
public:
    BSTIterator(TreeNode* root){
        for(TreeNode* node = root; node != NULL; node = node->left){
            st.push(node);
        }
    }
    
    TreeNode* nextNode(){
        TreeNode* currentNode = st.top(); st.pop();
        for(TreeNode* node = currentNode->right; node != NULL; node = node->left){
            st.push(node);
        }
        return currentNode;
    }
};

class BSTReversedIterator{
private:
    stack<TreeNode*> st;
    
public:
    BSTReversedIterator(TreeNode* root){
        for(TreeNode* node = root; node != NULL; node = node->right){
            st.push(node);
        }
    }
    
    TreeNode* nextNode(){
        TreeNode* currentNode = st.top(); st.pop();
        for(TreeNode* node = currentNode->left; node != NULL; node = node->right){
            st.push(node);
        }
        return currentNode;
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        BSTIterator bstIt(root);
        BSTReversedIterator bstRevIt(root);
        TreeNode* leftNode = bstIt.nextNode();
        TreeNode* rightNode = bstRevIt.nextNode();
        while(leftNode != rightNode){
            if(leftNode->val + rightNode->val < k){
                leftNode = bstIt.nextNode();
            }else if(leftNode->val + rightNode->val > k){
                rightNode = bstRevIt.nextNode();
            }else{
                return true;
            }
        }
        return false;
    }
};