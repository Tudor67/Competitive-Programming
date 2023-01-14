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
class BinaryTreeIterator{
private:
    TreeNode* currentNode;
    queue<TreeNode*> cache;

    void morrisStep(){
        while(currentNode != nullptr && cache.empty()){
            if(currentNode->left == nullptr){
                cache.push(nullptr);
                cache.push(currentNode);
                currentNode = currentNode->right;
            }else{
                TreeNode* predNode = currentNode->left;
                while(predNode->right != nullptr && predNode->right != currentNode){
                    predNode = predNode->right;
                }
                if(predNode->right == nullptr){
                    cache.push(currentNode);
                    predNode->right = currentNode;
                    currentNode = currentNode->left;
                }else{
                    cache.push(nullptr);
                    predNode->right = nullptr;
                    currentNode = currentNode->right;
                }
            }
        }
    }

public:
    BinaryTreeIterator(TreeNode* root){
        currentNode = root;
    }

    bool isEnd(){
        morrisStep();
        return (cache.empty());
    }

    TreeNode* next(){
        morrisStep();
        TreeNode* nextNode = cache.front();
        cache.pop();
        return nextNode;
    }
};

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        bool isSame = true;

        BinaryTreeIterator it1(p);
        BinaryTreeIterator it2(q);
        while(!it1.isEnd() && !it2.isEnd() && isSame){
            TreeNode* node1 = it1.next();
            TreeNode* node2 = it2.next();

            if((node1 == nullptr && node2 != nullptr) ||
               (node1 != nullptr && node2 == nullptr) ||
               (node1 != nullptr && node2 != nullptr && node1->val != node2->val)){
                isSame = false;
            }
        }

        if(it1.isEnd() != it2.isEnd()){
            isSame = false;
        }

        while(!it1.isEnd()){
            it1.next();
        }
        while(!it2.isEnd()){
            it2.next();
        }

        return isSame;
    }
};