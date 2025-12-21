class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        const int ROWS = strs.size();
        const int COLS = strs[0].length();

        int minDeletions = 0;
        for(int col = 0; col < COLS; ++col){
            bool isSortedCol = true;
            for(int row = 0; row + 1 < ROWS; ++row){
                if(strs[row][col] > strs[row + 1][col]){
                    isSortedCol = false;
                }
            }

            if(!isSortedCol){
                minDeletions += 1;
            }
        }

        return minDeletions;
    }
};