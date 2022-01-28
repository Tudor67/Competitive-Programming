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
    void stackPushLeft(stack<TreeNode*>& st, TreeNode* node){
        while(node != NULL){
            st.push(node);
            node = node->left;
        }
    }
    
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        stack<TreeNode*> st1;
        stack<TreeNode*> st2;
        
        stackPushLeft(st1, root1);
        stackPushLeft(st2, root2);
        
        vector<int> answer;
        while(!st1.empty() || !st2.empty()){
            if(st2.empty() || (!st1.empty() && st1.top()->val <= st2.top()->val)){
                answer.push_back(st1.top()->val);
                TreeNode* rightChild = st1.top()->right;
                st1.pop();
                stackPushLeft(st1, rightChild);
            }else{
                answer.push_back(st2.top()->val);
                TreeNode* rightChild = st2.top()->right;
                st2.pop();
                stackPushLeft(st2, rightChild);
            }
        }
        
        return answer;
    }
};