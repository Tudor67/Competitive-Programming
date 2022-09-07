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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> sumOf;
        vector<int> countOf;
        
        stack<pair<TreeNode*, int>> st;
        st.emplace(root, 0);
        while(!st.empty()){
            TreeNode* node = st.top().first;
            int level = st.top().second;
            st.pop();
            
            if(level >= (int)sumOf.size()){
                sumOf.resize(level + 1);
                countOf.resize(level + 1);
            }
            
            sumOf[level] += node->val;
            countOf[level] += 1;
            
            if(node->right != nullptr){
                st.emplace(node->right, level + 1);
            }
            if(node->left != nullptr){
                st.emplace(node->left, level + 1);
            }
        }
        
        const int H = sumOf.size();
        vector<double> averages(H);
        for(int level = 0; level < H; ++level){
            averages[level] = sumOf[level] / countOf[level];
        }
        
        return averages;
    }
};