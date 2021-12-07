class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        int startRow = startPos[0];
        int startCol = startPos[1];
        int endRow = homePos[0];
        int endCol = homePos[1];
        
        int rowCost = 0;
        if(startRow < endRow){
            rowCost = accumulate(rowCosts.begin() + startRow + 1, rowCosts.begin() + endRow + 1, 0);
        }else if(startRow > endRow){
            rowCost = accumulate(rowCosts.begin() + endRow, rowCosts.begin() + startRow, 0);
        }
        
        int colCost = 0;
        if(startCol < endCol){
            colCost = accumulate(colCosts.begin() + startCol + 1, colCosts.begin() + endCol + 1, 0);
        }else if(startCol > endCol){
            colCost = accumulate(colCosts.begin() + endCol, colCosts.begin() + startCol, 0);
        }
        
        return rowCost + colCost;
    }
};