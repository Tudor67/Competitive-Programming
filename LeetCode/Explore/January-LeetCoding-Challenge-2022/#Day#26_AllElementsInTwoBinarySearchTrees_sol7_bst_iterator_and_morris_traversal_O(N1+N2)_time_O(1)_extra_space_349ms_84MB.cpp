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

class BSTIterator{
private:
    const int INF = INT_MAX;
    TreeNode* currentNode;
    TreeNode* predecessorNode;
    int currentVal;
    
public:
    BSTIterator(TreeNode* root){
        currentNode = root;
        currentVal = INF;
        next();
    }
    
    int getCurrentVal(){
        return currentVal;
    }
    
    void next(){
        currentVal = INF;
        while(currentVal == INF && currentNode != NULL){
            if(currentNode->left == NULL){
                currentVal = currentNode->val;
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
                    predecessorNode->right = NULL;
                    currentVal = currentNode->val;
                    currentNode = currentNode->right;
                }
            }
        }
    }
    
    bool isEnd(){
        return (currentVal == INF);
    }
};

class Solution {
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        BSTIterator it1(root1);
        BSTIterator it2(root2);
        
        vector<int> answer;
        while(!it1.isEnd() || !it2.isEnd()){
            if(it2.isEnd() || (!it1.isEnd() && it1.getCurrentVal() <= it2.getCurrentVal())){
                answer.push_back(it1.getCurrentVal());
                it1.next();
            }else{
                answer.push_back(it2.getCurrentVal());
                it2.next();
            }
        }
        
        return answer;
    }
};