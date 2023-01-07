class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        const int ROWS = strs.size();
        const int COLS = strs[0].size();

        int res = 0;
        for(int col = 0; col < COLS; ++col){
            bool isSorted = true;
            for(int row = 1; row < ROWS; ++row){
                if(strs[row - 1][col] > strs[row][col]){
                    isSorted = false;
                    break;
                }
            }
            if(!isSorted){
                res += 1;
            }
        }

        return res;
    }
};