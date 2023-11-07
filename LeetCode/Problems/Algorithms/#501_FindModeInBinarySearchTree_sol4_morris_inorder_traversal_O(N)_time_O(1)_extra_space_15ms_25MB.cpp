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
    void updateResult(TreeNode* currNode, int& val, int& valCount, int& maxCount, vector<int>& modes){
        if(currNode->val == val){
            valCount += 1;
        }else{
            val = currNode->val;
            valCount = 1;
        }

        if(valCount > maxCount){
            maxCount = valCount;
            modes.clear();
            modes.push_back(val);
        }else if(valCount == maxCount){
            if(modes.empty() || modes.back() != val){
                modes.push_back(val);
            }
        }
    }

public:
    vector<int> findMode(TreeNode* root) {
        vector<int> modes;

        int val = INT_MIN;
        int valCount = 0;
        int maxCount = 0;

        TreeNode* currNode = root;
        while(currNode != nullptr){
            if(currNode->left == nullptr){
                updateResult(currNode, val, valCount, maxCount, modes);
                currNode = currNode->right;
            }else{
                TreeNode* predNode = currNode->left;
                while(predNode->right != nullptr && predNode->right != currNode){
                    predNode = predNode->right;
                }

                if(predNode->right == nullptr){
                    predNode->right = currNode;
                    currNode = currNode->left;
                }else{
                    updateResult(currNode, val, valCount, maxCount, modes);
                    predNode->right = nullptr;
                    currNode = currNode->right;
                }
            }
        }

        return modes;
    }
};