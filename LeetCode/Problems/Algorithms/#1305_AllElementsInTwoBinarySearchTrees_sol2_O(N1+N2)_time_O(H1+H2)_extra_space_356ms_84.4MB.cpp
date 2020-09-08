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
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> allElements;
        TreeNode* node1 = root1;
        TreeNode* node2 = root2;
        stack<TreeNode*> st1;
        stack<TreeNode*> st2;
        
        while(!st1.empty() || !st2.empty() || node1 != NULL || node2 != NULL){
            while(node1 != NULL){
                st1.push(node1);
                node1 = node1->left;
            }
            
            while(node2 != NULL){
                st2.push(node2);
                node2 = node2->left;
            }
            
            int val1 = (st1.empty() ? INT_MAX : st1.top()->val);
            int val2 = (st2.empty() ? INT_MAX : st2.top()->val);
            if(val1 <= val2){
                allElements.push_back(val1);
                node1 = st1.top()->right;
                st1.pop();
            }else{
                allElements.push_back(val2);
                node2 = st2.top()->right;
                st2.pop();
            }
        }
        
        return allElements;
    }
};