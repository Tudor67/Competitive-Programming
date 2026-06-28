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
        if(!valToNode.contains(val)){
            valToNode[val] = new TreeNode(val);
        }
        return valToNode[val];
    }

public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> valToNode;
        unordered_set<int> parentsValSet;
        unordered_set<int> childrenValSet;

        for(const vector<int>& DESC: descriptions){
            int parentVal = DESC[0];
            int childVal = DESC[1];
            int isLeftChild = DESC[2];

            TreeNode* parentNode = getNode(parentVal, valToNode);
            if(isLeftChild){
                parentNode->left = getNode(childVal, valToNode);
            }else{
                parentNode->right = getNode(childVal, valToNode);
            }
            parentsValSet.insert(parentVal);
            childrenValSet.insert(childVal);
        }

        for(int nodeVal: parentsValSet){
            if(!childrenValSet.contains(nodeVal)){
                return getNode(nodeVal, valToNode);
            }
        }

        return nullptr;
    }
};