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
    void inorder(TreeNode* root, vector<int>& v){
        if(root != NULL){
            inorder(root->left, v);
            v.push_back(root->val);
            inorder(root->right, v);
        }
    }
    
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> v1;
        inorder(root1, v1);
        
        vector<int> v2;
        inorder(root2, v2);
        
        const int N1 = v1.size();
        const int N2 = v2.size();
        vector<int> sortedElements;
        int i1 = 0;
        int i2 = 0;
        while(i1 < N1 || i2 < N2){
            if(i2 == N2 || (i1 < N1 && v1[i1] <= v2[i2])){
                sortedElements.push_back(v1[i1]);
                i1 += 1;
            }else{
                sortedElements.push_back(v2[i2]);
                i2 += 1;
            }
        }
        
        return sortedElements;
    }
};