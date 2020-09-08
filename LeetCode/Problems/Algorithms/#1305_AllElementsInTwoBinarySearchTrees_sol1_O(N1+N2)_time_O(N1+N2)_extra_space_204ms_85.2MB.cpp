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
    void inorder(TreeNode* node, vector<int>& elems){
        if(node != NULL){
            inorder(node->left, elems);
            elems.push_back(node->val);
            inorder(node->right, elems);
        }
    }
    
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        // inorder traversal
        vector<int> elems1;
        vector<int> elems2;
        inorder(root1, elems1);
        inorder(root2, elems2);
        
        // merge two sorted vectors
        const int N1 = elems1.size();
        const int N2 = elems2.size();
        vector<int> allElems(N1 + N2);
        
        int p1 = 0;
        int p2 = 0;
        while(p1 < N1 && p2 < N2){
            if(elems1[p1] < elems2[p2]){
                allElems[p1 + p2] = elems1[p1];
                p1 += 1;
            }else{
                allElems[p1 + p2] = elems2[p2];
                p2 += 1;
            }
        }
        
        for(; p1 < N1; ++p1){
            allElems[p1 + p2] = elems1[p1];
        }
        
        for(; p2 < N2; ++p2){
            allElems[p1 + p2] = elems2[p2];
        }
        
        return allElems;
    }
};