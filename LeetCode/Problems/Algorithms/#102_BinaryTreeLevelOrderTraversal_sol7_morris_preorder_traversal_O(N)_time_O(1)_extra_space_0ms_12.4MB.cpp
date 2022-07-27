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
    void addVal(vector<vector<int>>& res, int level, TreeNode* node){
        if((int)res.size() <= level){
            res.resize(level + 1);
        }
        res[level].push_back(node->val);
    }
    
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        
        TreeNode* cur = root;
        int level = 0;
        while(cur != NULL){
            if(cur->left == NULL){
                addVal(res, level, cur);
                cur = cur->right;
                level += 1;
            }else{
                TreeNode* pred = cur->left;
                int delta = 1;
                while(pred->right != NULL && pred->right != cur){
                    pred = pred->right;
                    delta += 1;
                }
                if(pred->right == NULL){
                    addVal(res, level, cur);
                    pred->right = cur;
                    cur = cur->left;
                    level += 1;
                }else{
                    pred->right = NULL;
                    cur = cur->right;
                    level -= delta;
                }
            }
        }
        
        return res;
    }
};