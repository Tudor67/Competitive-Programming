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
        const vector<pair<int, int>> DIRECTIONS = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        vector<vector<int>> res(ROWS, vector<int>(COLS, -1));

        int prevRow = 0;
        int prevCol = -1;
        int dirIndex = 0;
        for(ListNode* node = head; node != nullptr; node = node->next){
            int row = prevRow + DIRECTIONS[dirIndex].first;
            int col = prevCol + DIRECTIONS[dirIndex].second;
            if(!(0 <= row && row < ROWS && 0 <= col && col < COLS && res[row][col] == -1)){
                dirIndex = (dirIndex + 1) % 4;
                row = prevRow + DIRECTIONS[dirIndex].first;
                col = prevCol + DIRECTIONS[dirIndex].second;
            }
            res[row][col] = node->val;
            prevRow = row;
            prevCol = col;
        }

        return res;
    }
};