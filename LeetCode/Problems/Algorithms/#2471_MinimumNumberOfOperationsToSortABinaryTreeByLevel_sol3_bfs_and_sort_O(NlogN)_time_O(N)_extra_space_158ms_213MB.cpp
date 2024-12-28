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
    int computeMinOperations(vector<int>& values){
        unordered_map<int, int> indexOf;
        for(int i = 0; i < (int)values.size(); ++i){
            indexOf[values[i]] = i;
        }

        vector<int> sortedValues = values;
        sort(sortedValues.begin(), sortedValues.end());
        
        int minOperations = 0;
        for(int i = 0; i < (int)sortedValues.size(); ++i){
            if(indexOf[sortedValues[i]] != i){
                int j = indexOf[sortedValues[i]];
                swap(values[i], values[j]);
                indexOf[values[i]] = i;
                indexOf[values[j]] = j;
                minOperations += 1;
            }
        }

        return minOperations;
    }

public:
    int minimumOperations(TreeNode* root) {
        int minOperations = 0;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            vector<int> levelValues;
            levelValues.reserve(q.size());

            for(int i = q.size(); i >= 1; --i){
                TreeNode* node = q.front();
                q.pop();

                levelValues.push_back(node->val);

                if(node->left != nullptr){
                    q.push(node->left);
                }
                if(node->right != nullptr){
                    q.push(node->right);
                }
            }

            minOperations += computeMinOperations(levelValues);
        }

        return minOperations;
    }
};