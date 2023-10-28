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
    void updateResult(TreeNode* currNode, int currDepth, vector<int>& res){
        if((int)res.size() <= currDepth){
            res.resize(currDepth + 1, INT_MIN);
        }
        res[currDepth] = max(res[currDepth], currNode->val);
    }

public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;

        TreeNode* currNode = root;
        int currDepth = 0;

        while(currNode != nullptr){
            if(currNode->left == nullptr){
                updateResult(currNode, currDepth, res);
                currNode = currNode->right;
                currDepth += 1;
            }else{
                TreeNode* predNode = currNode->left;
                int depthDelta = 1;
                while(predNode->right != nullptr && predNode->right != currNode){
                    predNode = predNode->right;
                    depthDelta += 1;
                }

                if(predNode->right == nullptr){
                    updateResult(currNode, currDepth, res);
                    predNode->right = currNode;
                    currNode = currNode->left;
                    currDepth += 1;
                }else{
                    predNode->right = nullptr;
                    currNode = currNode->right;
                    currDepth -= depthDelta;
                }
            }
        }

        return res;
    }
};