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
class BTLeafIterator{
private:
    TreeNode* curr;
    TreeNode* pred;
    TreeNode* leaf;

public:
    BTLeafIterator(TreeNode* root){
        curr = root;
        leaf = nullptr;
    }

    bool hasNext(){
        while(curr != nullptr && leaf == nullptr){
            if(curr->left == nullptr){
                if(curr->right == nullptr){
                    leaf = curr;
                }
                curr = curr->right;
            }else{
                pred = curr->left;
                while(pred->right != nullptr && pred->right != curr){
                    pred = pred->right;
                }

                if(pred->right == nullptr){
                    pred->right = curr;
                    curr = curr->left;
                }else{
                    if(pred->left == nullptr){
                        leaf = pred;
                    }
                    pred->right = nullptr;
                    curr = curr->right;
                }
            }
        }

        return (leaf != nullptr);
    }

    TreeNode* next(){
        TreeNode* resNode = leaf;
        leaf = nullptr;
        return resNode;
    }
};

class Solution {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        BTLeafIterator it1(root1);
        BTLeafIterator it2(root2);

        bool areLeafSimilar = true;
        while(areLeafSimilar && it1.hasNext() && it2.hasNext()){
            if(it1.next()->val != it2.next()->val){
                areLeafSimilar = false;
            }
        }

        if(it1.hasNext() || it2.hasNext()){
            areLeafSimilar = false;
        }

        while(it1.hasNext()){
            it1.next();
        }

        while(it2.hasNext()){
            it2.next();
        }

        return areLeafSimilar;
    }
};