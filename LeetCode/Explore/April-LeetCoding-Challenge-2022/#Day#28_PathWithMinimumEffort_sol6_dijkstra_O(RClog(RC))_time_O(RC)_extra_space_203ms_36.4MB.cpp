class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        static const vector<pair<int, int>> DIRECTIONS = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        static const int INF = 1e9;
        
        const int ROWS = heights.size();
        const int COLS = heights[0].size();
        
        using State = tuple<int, int, int>;
        set<State> states;
        vector<vector<int>> minEffort(ROWS, vector<int>(COLS, INF));
        minEffort[0][0] = 0;
        states.emplace(minEffort[0][0], 0, 0);
        
        while(!states.empty()){
            int row = get<1>(*states.begin());
            int col = get<2>(*states.begin());
            states.erase(states.begin());
            
            if(row == ROWS - 1 && col == COLS - 1){
                break;
            }
            
            for(const pair<int, int>& DIRECTION: DIRECTIONS){
                int nextRow = row + DIRECTION.first;
                int nextCol = col + DIRECTION.second;
                if(0 <= nextRow && nextRow < ROWS && 0 <= nextCol && nextCol < COLS){
                    int localEffort = abs(heights[row][col] - heights[nextRow][nextCol]);
                    int pathEffort = max(minEffort[row][col], localEffort);
                    if(pathEffort < minEffort[nextRow][nextCol]){
                        states.erase({minEffort[nextRow][nextCol], nextRow, nextCol});
                        minEffort[nextRow][nextCol] = pathEffort;
                        states.emplace(minEffort[nextRow][nextCol], nextRow, nextCol);
                    }
                }
            }
        }
        
        return minEffort[ROWS - 1][COLS - 1];
    }
};