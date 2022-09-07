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
    void dfs(TreeNode* node, int level, vector<double>& sumOf, vector<int>& countOf){
        if(node != nullptr){
            if(level >= (int)sumOf.size()){
                sumOf.resize(level + 1);
                countOf.resize(level + 1);
            }
            sumOf[level] += node->val;
            countOf[level] += 1;
            dfs(node->left, level + 1, sumOf, countOf);
            dfs(node->right, level + 1, sumOf, countOf);
        }
    }
    
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> sumOf;
        vector<int> countOf;
        dfs(root, 0, sumOf, countOf);
        
        const int H = sumOf.size();
        vector<double> averages(H);
        for(int level = 0; level < H; ++level){
            averages[level] = sumOf[level] / countOf[level];
        }
        
        return averages;
    }
};