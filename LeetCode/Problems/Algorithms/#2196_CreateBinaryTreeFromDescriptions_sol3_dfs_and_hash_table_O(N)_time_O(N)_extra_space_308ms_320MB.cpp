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
    TreeNode* createBinaryTree(int nodeVal, unordered_map<int, int>& leftChild, unordered_map<int, int>& rightChild){
        TreeNode* node = new TreeNode(nodeVal);
        if(leftChild.contains(nodeVal)){
            node->left = createBinaryTree(leftChild[nodeVal], leftChild, rightChild);
        }
        if(rightChild.contains(nodeVal)){
            node->right = createBinaryTree(rightChild[nodeVal], leftChild, rightChild);
        }
        return node;
    }

public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, int> leftChild;
        unordered_map<int, int> rightChild;
        unordered_set<int> parentsSet;
        unordered_set<int> childrenSet;
        for(const vector<int>& DESC: descriptions){
            int parent = DESC[0];
            int child = DESC[1];
            int isLeftChild = DESC[2];
            if(isLeftChild){
                leftChild[parent] = child;
            }else{
                rightChild[parent] = child;
            }
            parentsSet.insert(parent);
            childrenSet.insert(child);
        }

        int root = 0;
        for(int node: parentsSet){
            if(!childrenSet.contains(node)){
                root = node;
                break;
            }
        }

        return createBinaryTree(root, leftChild, rightChild);
    }
};