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
        vector<int> sortedValues;
        
        while(!q.empty()){
            const int LEVEL_SIZE = q.size();
            values.resize(LEVEL_SIZE);
            
            for(int i = 0; i < LEVEL_SIZE; ++i){
                TreeNode* node = q.front();
                q.pop();
                
                values[i] = node->val;
                
                if(node->left != nullptr){
                    q.push(node->left);
                }
                if(node->right != nullptr){
                    q.push(node->right);
                }
            }
            
            sortedValues = values;
            sort(sortedValues.begin(), sortedValues.end());
            
            for(int index = 0; index < LEVEL_SIZE; ++index){
                while(true){
                    int targetIndex = lower_bound(sortedValues.begin() + index, sortedValues.end(), values[index])
                                      - sortedValues.begin();
                    if(index == targetIndex){
                        break;
                    }else{
                        swap(values[index], values[targetIndex]);
                        swapOperations += 1;
                    }
                }
            }
        }
        
        return swapOperations;
    }
};