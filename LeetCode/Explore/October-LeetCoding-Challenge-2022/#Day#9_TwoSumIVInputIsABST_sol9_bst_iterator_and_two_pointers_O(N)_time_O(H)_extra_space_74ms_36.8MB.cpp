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
    
    void addLeftPath(TreeNode* root){
        for(TreeNode* node = root; node != nullptr; node = node->left){
            st.push(node);
        }
    }
    
public:
    BSTIterator(TreeNode* root){
        addLeftPath(root);
    }
    
    TreeNode* next(){
        TreeNode* node = nullptr;
        if(!st.empty()){
            node = st.top();
            st.pop();
            addLeftPath(node->right);
        }
        return node;
    }
};

class BSTReversedIterator{
private:
    stack<TreeNode*> st;
    
    void addRightPath(TreeNode* root){
        for(TreeNode* node = root; node != nullptr; node = node->right){
            st.push(node);
        }
    }
    
public:
    BSTReversedIterator(TreeNode* root){
        addRightPath(root);
    }
    
    TreeNode* next(){
        TreeNode* node = nullptr;
        if(!st.empty()){
            node = st.top();
            st.pop();
            addRightPath(node->left);
        }
        return node;
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        BSTIterator leftIt(root);
        BSTReversedIterator rightIt(root);
        
        TreeNode* leftNode = leftIt.next();
        TreeNode* rightNode = rightIt.next();
        while(leftNode != rightNode){
            int sum = leftNode->val + rightNode->val;
            if(sum < k){
                leftNode = leftIt.next();
            }else if(sum > k){
                rightNode = rightIt.next();
            }else{
                return true;
            }
        }
        
        return false;
    }
};