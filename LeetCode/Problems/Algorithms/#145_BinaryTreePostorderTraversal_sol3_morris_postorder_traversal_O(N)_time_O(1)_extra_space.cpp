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
    void reverseRightLinks(TreeNode* startNode, TreeNode* endNode){
        TreeNode* previousNode = NULL;
        TreeNode* currentNode = startNode;
        TreeNode* nextNode = NULL;
        while(previousNode != endNode){
            nextNode = currentNode->right;
            currentNode->right = previousNode;
            previousNode = currentNode;
            currentNode = nextNode;
        }
    }
    
public:
    vector<int> postorderTraversal(TreeNode* root) {
        TreeNode* virtualRoot = new TreeNode(0, root, NULL);
        vector<int> postorderNodes;
        
        TreeNode* predecessorNode = NULL;
        TreeNode* currentNode = virtualRoot;
        while(currentNode != NULL){
            if(currentNode->left == NULL){
                currentNode = currentNode->right;
            }else{
                predecessorNode = currentNode->left;
                while(predecessorNode->right != NULL && predecessorNode->right != currentNode){
                    predecessorNode = predecessorNode->right;
                }
                if(predecessorNode->right == NULL){
                    predecessorNode->right = currentNode;
                    currentNode = currentNode->left;
                }else{
                    reverseRightLinks(currentNode->left, predecessorNode);
                    for(TreeNode* node = predecessorNode; node != NULL; node = node->right){
                        postorderNodes.push_back(node->val);
                    }
                    reverseRightLinks(predecessorNode, currentNode->left);
                    predecessorNode->right = NULL;
                    currentNode = currentNode->right;
                }
            }
        }
        
        delete virtualRoot;
        return postorderNodes;
    }
};