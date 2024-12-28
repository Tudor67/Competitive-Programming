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
    void update(TreeNode* currNode, int currLevel, vector<int>& levelMax){
        if(currLevel < (int)levelMax.size()){
            levelMax[currLevel] = max(levelMax[currLevel], currNode->val);
        }else{
            levelMax.push_back(currNode->val);
        }
    }

public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> levelMax;

        TreeNode* currNode = root;
        int currLevel = 0;

        while(currNode != nullptr){
            if(currNode->left == nullptr){
                update(currNode, currLevel, levelMax);
                currNode = currNode->right;
                currLevel += 1;
            }else{
                TreeNode* predNode = currNode->left;
                int deltaLevel = 1;
                while(predNode->right != nullptr && predNode->right != currNode){
                    predNode = predNode->right;
                    deltaLevel += 1;
                }

                if(predNode->right == nullptr){
                    update(currNode, currLevel, levelMax);
                    predNode->right = currNode;
                    currNode = currNode->left;
                    currLevel += 1;
                }else{
                    predNode->right = nullptr;
                    currNode = currNode->right;
                    currLevel -= deltaLevel;
                }
            }
        }

        return levelMax;
    }
};