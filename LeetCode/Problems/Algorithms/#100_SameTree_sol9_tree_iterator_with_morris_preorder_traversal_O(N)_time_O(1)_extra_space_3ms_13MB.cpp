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
    TreeNode* currNode;
    queue<TreeNode*> cache;

    void populateCache(){
        while(currNode != nullptr && cache.empty()){
            if(currNode->left == nullptr){
                cache.push(currNode);
                cache.push(nullptr);
                currNode = currNode->right;
            }else{
                TreeNode* predNode = currNode->left;
                while(predNode->right != nullptr && predNode->right != currNode){
                    predNode = predNode->right;
                }
                if(predNode->right == nullptr){
                    predNode->right = currNode;
                    cache.push(currNode);
                    currNode = currNode->left;
                }else{
                    predNode->right = nullptr;
                    cache.push(nullptr);
                    currNode = currNode->right;
                }
            }
        }
    }

public:
    BTIterator(TreeNode* root){
        currNode = root;
    }

    bool hasNext(){
        populateCache();
        return !cache.empty();
    }

    TreeNode* next(){
        populateCache();
        TreeNode* nextNode = cache.front();
        cache.pop();
        return nextNode;
    }
};

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        bool isSame = true;

        BTIterator it1(p);
        BTIterator it2(q);
        while(isSame && it1.hasNext() && it2.hasNext()){
            TreeNode* node1 = it1.next();
            TreeNode* node2 = it2.next();
            if(node1 == nullptr && node2 == nullptr){
                // ok
            }else if(node1 == nullptr || node2 == nullptr || node1->val != node2->val){
                isSame = false;
            }
        }

        if(it1.hasNext() || it2.hasNext()){
            isSame = false;
        }

        while(it1.hasNext()){
            it1.next();
        }

        while(it2.hasNext()){
            it2.next();
        }

        return isSame;
    }
};