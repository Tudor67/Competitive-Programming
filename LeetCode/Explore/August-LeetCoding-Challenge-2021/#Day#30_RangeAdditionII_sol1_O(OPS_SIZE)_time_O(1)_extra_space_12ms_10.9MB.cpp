class Solution {
public:
    int maxCount(int rows, int cols, vector<vector<int>>& ops) {
        int minRows = rows;
        int minCols = cols;
        for(const vector<int>& OP: ops){
            minRows = min(minRows, OP[0]);
            minCols = min(minCols, OP[1]);
        }
        return minRows * minCols;
    }
};