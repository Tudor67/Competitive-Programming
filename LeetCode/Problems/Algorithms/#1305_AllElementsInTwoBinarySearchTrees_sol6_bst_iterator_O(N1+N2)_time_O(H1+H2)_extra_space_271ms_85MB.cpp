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
    
    void pushLeftSubtree(TreeNode* node){
        while(node != NULL){
            st.push(node);
            node = node->left;
        }
    }
    
public:
    BSTIterator(TreeNode* root){
        pushLeftSubtree(root);
    }
    
    int getCurrentVal(){
        return st.top()->val;
    }
    
    void next(){
        TreeNode* rightChild = st.top()->right;
        st.pop();
        pushLeftSubtree(rightChild);
    }
    
    bool isEnd(){
        return st.empty();
    }
};

class Solution {
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        BSTIterator it1(root1);
        BSTIterator it2(root2);
        
        vector<int> answer;
        while(!it1.isEnd() || !it2.isEnd()){
            if(it2.isEnd() || (!it1.isEnd() && it1.getCurrentVal() <= it2.getCurrentVal())){
                answer.push_back(it1.getCurrentVal());
                it1.next();
            }else{
                answer.push_back(it2.getCurrentVal());
                it2.next();
            }
        }
        
        return answer;
    }
};