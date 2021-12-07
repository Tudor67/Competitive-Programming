class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        int startRow = startPos[0];
        int startCol = startPos[1];
        int endRow = homePos[0];
        int endCol = homePos[1];
        
        int minRow = min(startRow, endRow);
        int maxRow = max(startRow, endRow);
        int minCol = min(startCol, endCol);
        int maxCol = max(startCol, endCol);
        
        int rowCost = accumulate(rowCosts.begin() + minRow, rowCosts.begin() + maxRow + 1, 0) - rowCosts[startRow];
        int colCost = accumulate(colCosts.begin() + minCol, colCosts.begin() + maxCol + 1, 0) - colCosts[startCol];
        
        return rowCost + colCost;
    }
};