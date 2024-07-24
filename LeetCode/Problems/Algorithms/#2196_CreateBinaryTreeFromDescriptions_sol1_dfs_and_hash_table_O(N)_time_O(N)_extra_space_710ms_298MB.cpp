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
    TreeNode* createBinaryTree(int val, unordered_map<int, int>& leftChildOf, unordered_map<int, int>& rightChildOf){
        TreeNode* node = new TreeNode(val);
        if(leftChildOf.count(val)){
            node->left = createBinaryTree(leftChildOf[val], leftChildOf, rightChildOf);
        }
        if(rightChildOf.count(val)){
            node->right = createBinaryTree(rightChildOf[val], leftChildOf, rightChildOf);
        }
        return node;
    }

public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, int> leftChildOf;
        unordered_map<int, int> rightChildOf;
        unordered_set<int> childrenSet;
        for(const vector<int>& D: descriptions){
            int parent = D[0];
            int child = D[1];
            int isLeftChild = D[2];
            if(isLeftChild){
                leftChildOf[parent] = child;
            }else{
                rightChildOf[parent] = child;
            }
            childrenSet.insert(child);
        }

        int root = -1;
        for(const vector<int>& D: descriptions){
            int parent = D[0];
            if(!childrenSet.count(parent)){
                root = parent;
            }
        }

        return createBinaryTree(root, leftChildOf, rightChildOf);
    }
};