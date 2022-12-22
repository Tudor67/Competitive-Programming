class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        static const vector<pair<int, int>> DIRECTIONS = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        static const int INF = 1e9;
        const int ROWS = grid.size();
        const int COLS = grid[0].size();
        const int Q = queries.size();

        // sort queries and keep their original indices
        vector<pair<int, int>> sortedQueryIndex(Q);
        for(int i = 0; i < Q; ++i){
            sortedQueryIndex[i] = {queries[i], i};
        }
        
        sort(sortedQueryIndex.begin(), sortedQueryIndex.end());

        // dijkstra and two pointers
        vector<vector<int>> minThr(ROWS, vector<int>(COLS, INF));
        set<tuple<int, int, int>> statesSet;
        minThr[0][0] = grid[0][0];
        statesSet.insert({minThr[0][0], 0, 0});
        
        int i = 0;
        vector<int> diff(Q);
        while(!statesSet.empty() && i < Q){
            int row = get<1>(*statesSet.begin());
            int col = get<2>(*statesSet.begin());
            statesSet.erase(statesSet.begin());

            while(i < Q && sortedQueryIndex[i].first <= minThr[row][col]){
                i += 1;
            }
            if(i < Q){
                diff[i] += 1;
            }
            
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

        // prefix sum on difference array
        vector<int> answer(Q);
        for(int i = 1; i < Q; ++i){
            diff[i] += diff[i - 1];
        }

        for(int i = 0; i < Q; ++i){
            int queryIndex = sortedQueryIndex[i].second;
            answer[queryIndex] = diff[i];
        }

        return answer;
    }
};