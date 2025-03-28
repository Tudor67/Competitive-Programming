class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();
        const int Q = queries.size();

        // Step 1: sort queries and store their original indices
        vector<pair<int, int>> sortedQueries(Q);
        for(int i = 0; i < Q; ++i){
            sortedQueries[i] = {queries[i], i};
        }

        sort(sortedQueries.begin(), sortedQueries.end());

        // Step 2: run Dijkstra's algorithm from (0, 0)
        //         update the results for the sortedQueries using two pointers approach
        const vector<pair<int, int>> DIRECTIONS = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        const int INF = 1e9;
        using State = array<int, 3>;
        set<State> statesSet;
        vector<vector<int>> minCost(ROWS, vector<int>(COLS, INF));
        minCost[0][0] = grid[0][0];
        statesSet.insert({minCost[0][0], 0, 0});

        vector<int> answer(Q);
        int qIdx = 0;

        int visCells = 0;
        while(!statesSet.empty() && qIdx < Q){
            int row = (*statesSet.begin())[1];
            int col = (*statesSet.begin())[2];
            statesSet.erase(statesSet.begin());

            visCells += 1;

            while(qIdx < Q && sortedQueries[qIdx].first <= minCost[row][col]){
                answer[sortedQueries[qIdx].second] = visCells - 1;
                qIdx += 1;
            }

            for(const auto& [rowDir, colDir]: DIRECTIONS){
                int nextRow = row + rowDir;
                int nextCol = col + colDir;
                if(0 <= nextRow && nextRow < ROWS && 0 <= nextCol && nextCol < COLS){
                    if(minCost[row][col] < minCost[nextRow][nextCol]){
                        statesSet.erase({minCost[nextRow][nextCol], nextRow, nextCol});
                        minCost[nextRow][nextCol] = max(grid[nextRow][nextCol], minCost[row][col]);
                        statesSet.insert({minCost[nextRow][nextCol], nextRow, nextCol});
                    }
                }
            }
        }

        while(qIdx < Q){
            answer[sortedQueries[qIdx].second] = visCells;
            qIdx += 1;
        }

        return answer;
    }
};