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
class BTIterator{
private:
    const int LEAF_SHIFT = 1e8; // nodes with values >= LEAF_SHIFT are marked as leaf nodes
                                // with original value = node->val - LEAF_SHIFT
    TreeNode* currentNode; // current node in Morris Preorder Traversal
    TreeNode* predNode;    // inorder predecessor of currentNode in Morris Preorder Traversal
    TreeNode* itNode;      // current node of BTIterator

public:
    BTIterator(TreeNode* root){
        currentNode = root;
        predNode = nullptr;
        itNode = nullptr;
        next();
    }

    TreeNode* getNode(){
        return itNode;
    }

    bool isLeaf(){
        return (itNode != nullptr && itNode->val >= LEAF_SHIFT);
    }

    bool isEnd(){
        return (itNode == nullptr);
    }

    void next(){
        if(isLeaf()){
            itNode->val -= LEAF_SHIFT;
        }

        itNode = nullptr;
        while(currentNode != nullptr && itNode == nullptr){
            if(currentNode->left == nullptr){
                if(currentNode->right == nullptr){
                    currentNode->val += LEAF_SHIFT;
                }
                itNode = currentNode;
                currentNode = currentNode->right;
            }else{
                predNode = currentNode->left;
                while(predNode->right != nullptr && predNode->right != currentNode){
                    predNode = predNode->right;
                }
                if(predNode->right == nullptr){
                    if(predNode->left == nullptr){
                        predNode->val += LEAF_SHIFT;
                    }
                    itNode = currentNode;
                    predNode->right = currentNode;
                    currentNode = currentNode->left;
                }else{
                    predNode->right = nullptr;
                    currentNode = currentNode->right;
                }
            }
        }
    }
};

class Solution {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        BTIterator it1(root1);
        BTIterator it2(root2);

        while(!it1.isEnd() && !it2.isEnd()){
            while(!it1.isEnd() && !it1.isLeaf()){
                it1.next();
            }
            while(!it2.isEnd() && !it2.isLeaf()){
                it2.next();
            }

            if(it1.isLeaf() && it2.isLeaf() && it1.getNode()->val == it2.getNode()->val){
                it1.next();
                it2.next();
            }else{
                break;
            }
        }

        bool areLeafSimilar = (it1.isEnd() && it2.isEnd());

        // visit all nodes to restore the initial tree
        // (i.e., to remove the modified links inorderPredecessor->right = currentNode,
        //        and restore the original values of the leaf nodes)
        while(!it1.isEnd()){
            it1.next();
        }
        while(!it2.isEnd()){
            it2.next();
        }

        return areLeafSimilar;
    }
};