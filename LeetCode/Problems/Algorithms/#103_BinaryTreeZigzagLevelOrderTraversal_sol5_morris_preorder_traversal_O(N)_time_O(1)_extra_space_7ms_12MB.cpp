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
    void updateResult(TreeNode* currentNode, int currentLevel, vector<vector<int>>& res){
        if(currentLevel >= (int)res.size()){
            res.resize(currentLevel + 1);
        }
        res[currentLevel].push_back(currentNode->val);
    }

public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;

        TreeNode* currentNode = root;
        int currentLevel = 0;

        while(currentNode != nullptr){
            if(currentNode->left == nullptr){
                updateResult(currentNode, currentLevel, res);
                currentNode = currentNode->right;
                currentLevel += 1;
            }else{
                int delta = 1;
                TreeNode* predNode = currentNode->left;
                while(predNode->right != nullptr && predNode->right != currentNode){
                    predNode = predNode->right;
                    delta += 1;
                }
                if(predNode->right == nullptr){
                    updateResult(currentNode, currentLevel, res);
                    predNode->right = currentNode;
                    currentNode = currentNode->left;
                    currentLevel += 1;
                }else{
                    predNode->right = nullptr;
                    currentNode = currentNode->right;
                    currentLevel -= delta;
                }
            }
        }

        for(int level = 1; level < (int)res.size(); level += 2){
            reverse(res[level].begin(), res[level].end());
        }

        return res;
    }
};