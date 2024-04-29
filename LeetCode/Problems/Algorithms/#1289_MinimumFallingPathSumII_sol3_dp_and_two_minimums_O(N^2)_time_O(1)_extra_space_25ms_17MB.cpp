class Solution {
private:
    void updateMinimums(pair<int, int>& p, pair<int, int>& currMin1, pair<int, int>& currMin2){
        if(p < currMin1){
            currMin2 = currMin1;
            currMin1 = p;
        }else if(p < currMin2){
            currMin2 = p;
        }
    }

public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();
        const int INF = 1e9;

        pair<int, int> currMin1 = {INF, -1};
        pair<int, int> currMin2 = {INF, -1};
        for(int col = 0; col < COLS; ++col){
            pair<int, int> p = {grid[0][col], col};
            updateMinimums(p, currMin1, currMin2);
        }

        for(int row = 1; row < ROWS; ++row){
            pair<int, int> prevMin1 = currMin1;
            pair<int, int> prevMin2 = currMin2;
            currMin1 = {INF, -1};
            currMin2 = {INF, -1};
            for(int col = 0; col < COLS; ++col){
                pair<int, int> p;
                if(prevMin1.second == col){
                    p = {prevMin2.first + grid[row][col], col};
                }else{
                    p = {prevMin1.first + grid[row][col], col};
                }
                updateMinimums(p, currMin1, currMin2);
            }
        }

        return currMin1.first;
    }
};