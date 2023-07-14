/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    void storePathToTarget(TreeNode* node, TreeNode* target, vector<TreeNode*>& pathToTarget){
        if(node == nullptr){
            return;
        }
        if(!pathToTarget.empty() && pathToTarget.back() == target){
            return;
        }
        pathToTarget.push_back(node);
        storePathToTarget(node->left, target, pathToTarget);
        storePathToTarget(node->right, target, pathToTarget);
        if(pathToTarget.back() != target){
            pathToTarget.pop_back();
        }
    }

    void collectNodesAtDistK(TreeNode* node, TreeNode* blockNode, int k, vector<int>& res){
        if(node == nullptr || node == blockNode || k < 0){
            return;
        }
        if(k == 0){
            res.push_back(node->val);
        }else{
            collectNodesAtDistK(node->left, blockNode, k - 1, res);
            collectNodesAtDistK(node->right, blockNode, k - 1, res);
        }
    }

public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<TreeNode*> pathToTarget;
        storePathToTarget(root, target, pathToTarget);

        vector<int> res;
        pathToTarget.push_back(nullptr);
        while(k >= 0 && (int)pathToTarget.size() >= 2){
            int size = pathToTarget.size();
            collectNodesAtDistK(pathToTarget[size - 2], pathToTarget[size - 1], k, res);
            k -= 1;
            pathToTarget.pop_back();
        }
        
        return res;
    }
};