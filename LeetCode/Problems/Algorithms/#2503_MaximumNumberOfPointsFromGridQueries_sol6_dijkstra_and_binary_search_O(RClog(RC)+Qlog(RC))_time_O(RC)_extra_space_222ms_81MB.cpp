class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();
        const int Q = queries.size();

        // Step 1: run Dijkstra's algorithm from (0, 0)
        //         minCost[row][col] is the min cost of a path from (0, 0) to (row, col)
        //         the cost of a path is defined as the max grid value enconuntered along the path
        const vector<pair<int, int>> DIRECTIONS = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        const int INF = 1e9;
        using State = array<int, 3>;
        set<State> statesSet;
        vector<vector<int>> minCost(ROWS, vector<int>(COLS, INF));
        minCost[0][0] = grid[0][0];
        statesSet.insert({minCost[0][0], 0, 0});

        vector<int> sortedMinCosts;
        sortedMinCosts.reserve(ROWS * COLS);

        while(!statesSet.empty()){
            int row = (*statesSet.begin())[1];
            int col = (*statesSet.begin())[2];
            statesSet.erase(statesSet.begin());

            sortedMinCosts.push_back(minCost[row][col]);

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

        // Step 2: the answer for value x is the total number of min costs less than x
        //         binary search the first occurrence of val (val >= x) in sortedMinCosts
        vector<int> answer(Q);
        for(int i = 0; i < Q; ++i){
            answer[i] = lower_bound(sortedMinCosts.begin(), sortedMinCosts.end(), queries[i])
                        - sortedMinCosts.begin();
        }

        return answer;
    }
};