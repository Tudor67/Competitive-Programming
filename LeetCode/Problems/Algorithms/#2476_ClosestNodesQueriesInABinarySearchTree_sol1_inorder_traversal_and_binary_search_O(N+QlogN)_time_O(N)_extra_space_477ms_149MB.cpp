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
    void inorderTraversal(TreeNode* root, vector<int>& sortedValues){
        if(root != nullptr){
            inorderTraversal(root->left, sortedValues);
            sortedValues.push_back(root->val);
            inorderTraversal(root->right, sortedValues);
        }
    }
    
public:
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<int> sortedValues;
        inorderTraversal(root, sortedValues);
        
        const int Q = queries.size();
        vector<vector<int>> answer(Q, vector<int>(2, -1));
        for(int i = 0; i < Q; ++i){
            vector<int>::iterator it = upper_bound(sortedValues.begin(), sortedValues.end(), queries[i]);
            if(it != sortedValues.begin()){
                answer[i][0] = *prev(it);
            }
            it = lower_bound(sortedValues.begin(), sortedValues.end(), queries[i]);
            if(it != sortedValues.end()){
                answer[i][1] = *it;
            }
        }
        
        return answer;
    }
};