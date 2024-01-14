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
class BTLeafIterator{
private:
    stack<TreeNode*> st;

public:
    BTLeafIterator(TreeNode* root){
        if(root != nullptr){
            st.push(root);
        }
    }

    bool hasNext(){
        return !st.empty();
    }

    TreeNode* next(){
        TreeNode* leafNode = nullptr;

        while(!st.empty() && leafNode == nullptr){
            TreeNode* node = st.top();
            st.pop();

            if(node->left == nullptr && node->right == nullptr){
                leafNode = node;
            }
            if(node->right != nullptr){
                st.push(node->right);
            }
            if(node->left != nullptr){
                st.push(node->left);
            }
        }

        return leafNode;
    }
};

class Solution {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        BTLeafIterator it1(root1);
        BTLeafIterator it2(root2);

        while(it1.hasNext() && it2.hasNext()){
            if(it1.next()->val != it2.next()->val){
                return false;
            }
        }

        return !it1.hasNext() && !it2.hasNext();
    }
};