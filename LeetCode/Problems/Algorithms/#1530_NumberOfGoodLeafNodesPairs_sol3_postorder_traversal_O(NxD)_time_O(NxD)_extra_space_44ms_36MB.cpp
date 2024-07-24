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
    vector<int> countLeafs(TreeNode* node, int distance, int& goodPairs){
        if(node == nullptr){
            return {};
        }
        if(node->left == nullptr && node->right == nullptr){
            return {1};
        }

        vector<int> lContrib = countLeafs(node->left, distance, goodPairs);
        vector<int> rContrib = countLeafs(node->right, distance, goodPairs);
        lContrib.resize(distance + 1);
        rContrib.resize(distance + 1);

        int j = distance;
        int rContribSum = accumulate(rContrib.begin(), rContrib.end(), 0);
        for(int i = 0; i <= distance; ++i){
            while(j >= 0 && i + j + 2 > distance){
                rContribSum -= rContrib[j];
                j -= 1;
            }
            goodPairs += lContrib[i] * rContribSum;
        }

        vector<int> leafsAtDist(distance + 1);
        for(int i = 0; i + 1 <= distance; ++i){
            leafsAtDist[i + 1] = lContrib[i] + rContrib[i];
        }

        return leafsAtDist;
    }

public:
    int countPairs(TreeNode* root, int distance) {
        int goodPairs = 0;
        countLeafs(root, distance, goodPairs);
        return goodPairs;
    }
};