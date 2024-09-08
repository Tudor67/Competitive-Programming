/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    void updateLPS(vector<int>& values, vector<int>& lps){
        if(lps.empty()){
            lps.push_back(0);
        }
        int diff = (int)values.size() - (int)lps.size();
        for(int i = (int)values.size() - diff; i < (int)values.size(); ++i){
            int k = lps.back();
            while(k > 0 && values[k] != values[i]){
                k = lps[k - 1];
            }
            if(values[k] == values[i]){
                k += 1;
            }
            lps.push_back(k);
        }
    }

    void dfs(TreeNode* node, vector<int>& values, vector<int>& lps, int listSize, bool& isMatching){
        if(node == nullptr || isMatching){
            return;
        }

        values.push_back(node->val);
        updateLPS(values, lps);

        if(lps.back() == listSize){
            isMatching = true;
        }

        dfs(node->left, values, lps, listSize, isMatching);
        dfs(node->right, values, lps, listSize, isMatching);

        values.pop_back();
        lps.pop_back();
    }

public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        vector<int> values;
        vector<int> lps;
        for(ListNode* node = head; node != nullptr; node = node->next){
            values.push_back(node->val);
        }
        values.push_back(INT_MIN);

        int listSize = (int)values.size() - 1;
        bool isMatching = false;
        dfs(root, values, lps, listSize, isMatching);

        return isMatching;
    }
};