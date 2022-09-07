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
    const int SHIFT = 1e4 + 1;
    const int BITS = 15;
    const int NODE_VAL_MASK = (1 << BITS) - 1;
    // During the Morris Preorder Traversal:
    // * encode current node value and current prefix max value in a 32-signed int:
    //   first encoding step:  shift values from range [-10^4 .. 10^4] to [1 .. 2 * 10^4 + 1]
    //                         (current node value + SHIFT and current prefix max value + SHIFT)
    //   second encoding step: put shifted node value on the first 15 bits [0 .. 14] and
    //                             shifted prefix max value on the next 15 bits [15 .. 29] of our code integer
    //                         code = (node value + SHIFT) | (prefix max value + SHIFT)
    // * for decoding we simply extract the first 15 bits of the code and subtract the SHIFT value
    //   initial node value = (code & ((1 << 15) - 1)) - SHIFT
    // * values of the nodes are modified during the morris traversal
    // * when the traversal is over, all the nodes are reset to their initial values
    
    void decode(TreeNode* currentNode){
        currentNode->val = (currentNode->val & NODE_VAL_MASK) - SHIFT;
    }
    
    void encode(TreeNode* currentNode, int prefMax){
        int code = (currentNode->val + SHIFT) | ((prefMax + SHIFT) << BITS);
        currentNode->val = code;
    }
    
    void updateAndEncodeLeftChild(TreeNode* currentNode, int& goodNodesCount){
        int prefMax = (currentNode->val >> BITS) - SHIFT;
        if(prefMax <= currentNode->left->val){
            goodNodesCount += 1;
        }
        encode(currentNode->left, max(currentNode->left->val, prefMax));
    }
    
    void updateAndEncodeRightChild(TreeNode* currentNode, int& goodNodesCount){
        if(currentNode->right != nullptr && ((currentNode->right->val <= 0) ||
                                             (currentNode->right->val >> BITS) == 0)){
            int prefMax = (currentNode->val >> BITS) - SHIFT;
            if(prefMax <= currentNode->right->val){
                goodNodesCount += 1;
            }
            encode(currentNode->right, max(currentNode->right->val, prefMax));
        }
    }
    
public:
    int goodNodes(TreeNode* root) {
        int goodNodesCount = 1;
        
        int prefMax = root->val;
        encode(root, root->val);
        
        TreeNode* currentNode = root;
        while(currentNode != nullptr){
            if(currentNode->left == nullptr){
                updateAndEncodeRightChild(currentNode, goodNodesCount);
                decode(currentNode);
                currentNode = currentNode->right;
            }else{
                TreeNode* pred = currentNode->left;
                while(pred->right != nullptr && pred->right != currentNode){
                    pred = pred->right;
                }
                if(pred->right == nullptr){
                    updateAndEncodeLeftChild(currentNode, goodNodesCount);
                    pred->right = currentNode;
                    currentNode = currentNode->left;
                }else{
                    updateAndEncodeRightChild(currentNode, goodNodesCount);
                    decode(currentNode);
                    pred->right = nullptr;
                    currentNode = currentNode->right;
                }
            }
        }
        
        return goodNodesCount;
    }
};