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
    void dfs(TreeNode* node, unordered_map<TreeNode*, TreeNode*>& parentOf, vector<TreeNode*>& startNodes){
        if(node != nullptr){
            parentOf[node->left] = node;
            parentOf[node->right] = node;
            if(node->left == nullptr && node->right == nullptr){
                startNodes.push_back(node);
            }
            dfs(node->left, parentOf, startNodes);
            dfs(node->right, parentOf, startNodes);
        }
    }

public:
    string smallestFromLeaf(TreeNode* root) {
        unordered_map<TreeNode*, TreeNode*> parentOf;
        vector<TreeNode*> startNodes;
        dfs(root, parentOf, startNodes);

        string res;
        vector<TreeNode*> nextStartNodes;
        while(!startNodes.empty()){
            int minVal = startNodes[0]->val;
            for(TreeNode* node: startNodes){
                minVal = min(minVal, node->val);
            }

            res.push_back(char(minVal + 'a'));

            if(minVal == root->val && find(startNodes.begin(), startNodes.end(), root) != startNodes.end()){
                break;
            }

            nextStartNodes.clear();
            for(TreeNode* node: startNodes){
                if(node->val == minVal){
                    nextStartNodes.push_back(parentOf[node]);
                }
            }
            startNodes = nextStartNodes;
        }

        return res;
    }
};