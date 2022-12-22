class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        static const vector<pair<int, int>> DIRECTIONS = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        const int ROWS = grid.size();
        const int COLS = grid[0].size();
        const int Q = queries.size();

        // use min heap to process neighboring cells in increasing order
        using T3 = tuple<int, int, int>;
        priority_queue<T3, vector<T3>, greater<T3>> minHeap;
        vector<vector<bool>> vis(ROWS, vector<bool>(COLS, false));
        minHeap.push({grid[0][0], 0, 0});
        vis[0][0] = true;

        vector<int> cellValues;
        cellValues.reserve(ROWS * COLS);
        while(!minHeap.empty()){
            int thr = get<0>(minHeap.top());
            int row = get<1>(minHeap.top());
            int col = get<2>(minHeap.top());
            minHeap.pop();

            cellValues.push_back(thr);
            
            for(const pair<int, int>& DIRECTION: DIRECTIONS){
                int nextRow = row + DIRECTION.first;
                int nextCol = col + DIRECTION.second;
                if(0 <= nextRow && nextRow < ROWS && 0 <= nextCol && nextCol < COLS && !vis[nextRow][nextCol]){
                    vis[nextRow][nextCol] = true;
                    minHeap.push({max(thr, grid[nextRow][nextCol]), nextRow, nextCol});
                }
            }
        }

        vector<int> answer(Q);
        for(int i = 0; i < Q; ++i){
            answer[i] = lower_bound(cellValues.begin(), cellValues.end(), queries[i]) - cellValues.begin();
        }

        return answer;
    }
};