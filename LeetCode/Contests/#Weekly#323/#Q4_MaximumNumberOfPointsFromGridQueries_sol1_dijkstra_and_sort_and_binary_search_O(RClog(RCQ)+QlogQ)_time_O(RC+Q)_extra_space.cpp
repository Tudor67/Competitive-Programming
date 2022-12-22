class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        static const vector<pair<int, int>> DIRECTIONS = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        static const int INF = 1e9;
        const int ROWS = grid.size();
        const int COLS = grid[0].size();
        const int Q = queries.size();
        
        // Step 1: use Dijkstra's algorithm to compute minThr[row][col];
        //         minThr[row][col]: min threshold in the best path from cell (0, 0) to cell (row, col);
        vector<vector<int>> minThr(ROWS, vector<int>(COLS, INF));
        set<tuple<int, int, int>> statesSet;
        minThr[0][0] = grid[0][0];
        statesSet.insert({minThr[0][0], 0, 0});
        
        while(!statesSet.empty()){
            int row = get<1>(*statesSet.begin());
            int col = get<2>(*statesSet.begin());
            statesSet.erase(statesSet.begin());
            
            for(const pair<int, int>& DIRECTION: DIRECTIONS){
                int nextRow = row + DIRECTION.first;
                int nextCol = col + DIRECTION.second;
                if(0 <= nextRow && nextRow < ROWS && 0 <= nextCol && nextCol < COLS){
                    if(max(minThr[row][col], grid[nextRow][nextCol]) < minThr[nextRow][nextCol]){
                        statesSet.erase({minThr[nextRow][nextCol], nextRow, nextCol});
                        minThr[nextRow][nextCol] = max(minThr[row][col], grid[nextRow][nextCol]);
                        statesSet.insert({minThr[nextRow][nextCol], nextRow, nextCol});
                    }
                }
            }
        }

        // Step 2: * sort queries (keep indices in original vector);
        //         * use binary search to find the smallest query index idx that satisfies
        //           the condition sortedQueries[idx] > minThr[row][col];
        //         * use difference array to mark the smallest query index idx from previous step;
        //         * intuition:
        //           * we can take cell (row, col) with sortedQueries[idx] when sortedQueries[idx] > minThr[row][col];
        //           * if we can take cell (row, col) with sortedQueries[idx], we also can take this cell with
        //             sortedQueries[idx + 1], sortedQueries[idx + 2], ...;
        vector<pair<int, int>> sortedQueryIndex(Q);
        for(int i = 0; i < Q; ++i){
            sortedQueryIndex[i] = {queries[i], i};
        }
        
        sort(sortedQueryIndex.begin(), sortedQueryIndex.end());

        vector<int> diff(Q);
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                int idx = upper_bound(sortedQueryIndex.begin(), sortedQueryIndex.end(), pair<int, int>{minThr[row][col], INF})
                          - sortedQueryIndex.begin();
                if(idx < Q){
                    diff[idx] += 1;
                }
            }
        }
        
        for(int i = 1; i < Q; ++i){
            diff[i] += diff[i - 1];
        }
        
        // Step 3: compute answer[i] for queries[i]
        //         (using indices of original queries)
        vector<int> answer(Q);
        for(int i = 0; i < Q; ++i){
            int queryIndex = sortedQueryIndex[i].second;
            answer[queryIndex] = diff[i];
        }
        
        return answer;
    }
};