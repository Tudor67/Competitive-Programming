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
    void addLeftPath(TreeNode* node, stack<TreeNode*>& st){
        while(node != nullptr){
            st.push(node);
            node = node->left;
        }
    }
    
public:
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> st;
        addLeftPath(root, st);
        
        bool isValid = true;
        TreeNode* prevNode = nullptr;
        while(!st.empty() && isValid){
            TreeNode* currentNode = st.top();
            st.pop();
            
            if(prevNode != nullptr && prevNode->val >= currentNode->val){
                isValid = false;
            }
            prevNode = currentNode;
            
            if(currentNode->right != nullptr && isValid){
                addLeftPath(currentNode->right, st);
            }
        }
        
        return isValid;
    }
};