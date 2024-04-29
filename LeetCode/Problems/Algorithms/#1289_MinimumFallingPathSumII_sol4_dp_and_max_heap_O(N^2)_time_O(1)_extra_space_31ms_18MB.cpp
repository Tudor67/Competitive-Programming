class Solution {
private:
    void updateHeap(priority_queue<pair<int, int>>& maxHeap, const pair<int, int>& P){
        maxHeap.push(P);
        if((int)maxHeap.size() > 2){
            maxHeap.pop();
        }
    }

public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();

        priority_queue<pair<int, int>> maxHeap;
        for(int col = 0; col < COLS; ++col){
            updateHeap(maxHeap, {grid[0][col], col});
        }

        for(int row = 1; row < ROWS; ++row){
            pair<int, int> prevMin2 = maxHeap.top(); maxHeap.pop();
            pair<int, int> prevMin1 = maxHeap.top(); maxHeap.pop();
            for(int col = 0; col < COLS; ++col){
                if(prevMin1.second == col){
                    updateHeap(maxHeap, {prevMin2.first + grid[row][col], col});
                }else{
                    updateHeap(maxHeap, {prevMin1.first + grid[row][col], col});
                }
            }
        }

        maxHeap.pop();
        return maxHeap.top().first;
    }
};