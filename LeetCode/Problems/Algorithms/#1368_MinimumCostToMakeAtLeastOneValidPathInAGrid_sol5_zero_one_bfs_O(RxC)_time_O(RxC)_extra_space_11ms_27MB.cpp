class Solution {
private:
    bool isInside(int row, int col, const int ROWS, const int COLS){
        return (0 <= row && row < ROWS && 0 <= col && col < COLS);
    }

public:
    int minCost(vector<vector<int>>& grid) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();
        const int INF = 1e9;
        const vector<pair<int, int>> DIRECTIONS = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        vector<vector<int>> minCost(ROWS, vector<int>(COLS, INF));
        minCost[0][0] = 0;

        deque<pair<int, int>> statesDQ;
        statesDQ.push_front({0, 0});

        while(!statesDQ.empty()){
            int row = statesDQ.front().first;
            int col = statesDQ.front().second;
            statesDQ.pop_front();

            for(int i = 0; i < DIRECTIONS.size(); ++i){
                int nextRow = row + DIRECTIONS[i].first;
                int nextCol = col + DIRECTIONS[i].second;
                if(isInside(nextRow, nextCol, ROWS, COLS)){
                    int arcCost = (int)(i + 1 != grid[row][col]);
                    int nextCost = minCost[row][col] + arcCost;
                    if(minCost[nextRow][nextCol] > nextCost){
                        minCost[nextRow][nextCol] = nextCost;
                        if(arcCost == 0){
                            statesDQ.push_front({nextRow, nextCol});
                        }else if(arcCost == 1){
                            statesDQ.push_back({nextRow, nextCol});
                        }
                    }
                }
            }
        }

        return minCost[ROWS - 1][COLS - 1];
    }
};