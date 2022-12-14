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
class BTIterator{
private:
    stack<TreeNode*> st;

public:
    BTIterator(TreeNode* root){
        if(root != nullptr){
            st.push(root);
        }
    }

    TreeNode* getNode(){
        if(st.empty()){
            return nullptr;
        }
        return st.top();
    }

    bool isLeaf(){
        return (!st.empty() && st.top()->left == nullptr && st.top()->right == nullptr);
    }

    bool isEnd(){
        return st.empty();
    }

    void next(){
        TreeNode* node = st.top();
        st.pop();
        if(node->right != nullptr){
            st.push(node->right);
        }
        if(node->left != nullptr){
            st.push(node->left);
        }
    }
};

class Solution {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        BTIterator it1(root1);
        BTIterator it2(root2);

        while(!it1.isEnd() && !it2.isEnd()){
            while(!it1.isEnd() && !it1.isLeaf()){
                it1.next();
            }
            while(!it2.isEnd() && !it2.isLeaf()){
                it2.next();
            }
            
            if(it1.isLeaf() && it2.isLeaf() && it1.getNode()->val == it2.getNode()->val){
                it1.next();
                it2.next();
            }else{
                break;
            }
        }

        return (it1.isEnd() && it2.isEnd());
    }
};