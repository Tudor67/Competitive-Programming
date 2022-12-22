class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        static const vector<pair<int, int>> DIRECTIONS = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        const int ROWS = grid.size();
        const int COLS = grid[0].size();
        const int Q = queries.size();

        // sort queries and keep their original indices
        vector<pair<int, int>> sortedQueryIndex(Q);
        for(int i = 0; i < Q; ++i){
            sortedQueryIndex[i] = {queries[i], i};
        }
        
        sort(sortedQueryIndex.begin(), sortedQueryIndex.end());

        // use min heap to process neighboring cells in increasing order
        using T3 = tuple<int, int, int>;
        priority_queue<T3, vector<T3>, greater<T3>> minHeap;
        vector<vector<bool>> vis(ROWS, vector<bool>(COLS, false));
        minHeap.push({grid[0][0], 0, 0});
        vis[0][0] = true;

        int visCount = 0;
        vector<int> answer(Q);
        for(int i = 0; i < Q; ++i){
            int queryVal = sortedQueryIndex[i].first;
            int queryIndex = sortedQueryIndex[i].second;

            while(!minHeap.empty() && get<0>(minHeap.top()) < queryVal){
                int thr = get<0>(minHeap.top());
                int row = get<1>(minHeap.top());
                int col = get<2>(minHeap.top());
                minHeap.pop();

                visCount += 1;

                for(const pair<int, int>& DIRECTION: DIRECTIONS){
                    int nextRow = row + DIRECTION.first;
                    int nextCol = col + DIRECTION.second;
                    if(0 <= nextRow && nextRow < ROWS && 0 <= nextCol && nextCol < COLS && !vis[nextRow][nextCol]){
                        vis[nextRow][nextCol] = true;
                        minHeap.push({max(thr, grid[nextRow][nextCol]), nextRow, nextCol});
                    }
                }
            }

            answer[queryIndex] = visCount;
        }

        return answer;
    }
};