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
    TreeNode* getNode(int val, unordered_map<int, TreeNode*>& valToNode){
        if(!valToNode.count(val)){
            valToNode[val] = new TreeNode(val);
        }
        return valToNode[val];
    }

public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> valToNode;
        unordered_set<int> childrenValuesSet;
        for(const vector<int>& D: descriptions){
            TreeNode* parent = getNode(D[0], valToNode);
            TreeNode* child = getNode(D[1], valToNode);
            int isLeftChild = D[2];
            if(isLeftChild){
                parent->left = child;
            }else{
                parent->right = child;
            }
            childrenValuesSet.insert(child->val);
        }

        for(const vector<int>& D: descriptions){
            TreeNode* parent = getNode(D[0], valToNode);
            if(!childrenValuesSet.count(parent->val)){
                return parent;
            }
        }

        return nullptr;
    }
};