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
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        
        int swapOperations = 0;
        vector<int> values;
        set<pair<int, int>> valIndexSet;
        
        while(!q.empty()){
            const int LEVEL_SIZE = q.size();
            values.resize(LEVEL_SIZE);
            
            for(int i = 0; i < LEVEL_SIZE; ++i){
                TreeNode* node = q.front();
                q.pop();
                
                values[i] = node->val;
                valIndexSet.insert({values[i], i});
                
                if(node->left != nullptr){
                    q.push(node->left);
                }
                if(node->right != nullptr){
                    q.push(node->right);
                }
            }
            
            for(int i = 0; i < LEVEL_SIZE; ++i){
                int j = valIndexSet.begin()->second;
                valIndexSet.erase(valIndexSet.begin());
                
                if(i != j){
                    valIndexSet.erase({values[i], i});
                    valIndexSet.erase({values[j], j});
                    swap(values[i], values[j]);
                    valIndexSet.insert({values[j], j});
                    swapOperations += 1;
                }
            }
        }
        
        return swapOperations;
    }
};