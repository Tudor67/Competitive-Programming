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
class Solution {
public:
    vector<vector<int>> spiralMatrix(int ROWS, int COLS, ListNode* head) {
        vector<vector<int>> res(ROWS, vector<int>(COLS, -1));

        int topRow = 0;
        int bottomRow = ROWS - 1;
        int leftCol = 0;
        int rightCol = COLS - 1;
        ListNode* node = head;

        while(node != nullptr){
            for(int col = leftCol; col <= rightCol && node != nullptr; ++col, node = node->next){
                res[topRow][col] = node->val;
            }
            topRow += 1;
            for(int row = topRow; row <= bottomRow && node != nullptr; ++row, node = node->next){
                res[row][rightCol] = node->val;
            }
            rightCol -= 1;
            for(int col = rightCol; col >= leftCol && node != nullptr; --col, node = node->next){
                res[bottomRow][col] = node->val;
            }
            bottomRow -= 1;
            for(int row = bottomRow; row >= topRow && node != nullptr; --row, node = node->next){
                res[row][leftCol] = node->val;
            }
            leftCol += 1;
        }

        return res;
    }
};