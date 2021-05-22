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
    const int INF = 1e7;
    
    tuple<int, int, int> solve(TreeNode* root){
        if(root == NULL){
            return {INF, 0, 0};
        }
        
        int leftCost1, leftCost2, leftCost3;
        int rightCost1, rightCost2, rightCost3;
        tie(leftCost1, leftCost2, leftCost3) = solve(root->left);
        tie(rightCost1, rightCost2, rightCost3) = solve(root->right);
        
        // min cost to cover subtrees when we put a camera on the root (cover the root)
        int cost1 = 1 + min({leftCost1, leftCost2, leftCost3}) + min({rightCost1, rightCost2, rightCost3});
        
        // min cost to cover subtrees when we do not put a camera on the root (cover the root)
        int cost2 = min(leftCost1 + min(rightCost1, rightCost2), min(leftCost1, leftCost2) + rightCost1);
        
        // min cost to cover subtrees when we do not put a camera on the root (do not cover the root)
        int cost3 = leftCost2 + rightCost2;
        
        return {cost1, cost2, cost3};
    }
    
public:
    int minCameraCover(TreeNode* root) {
        int cost1, cost2, cost3;
        tie(cost1, cost2, cost3) = solve(root);
        return min(cost1, cost2);
    }
};