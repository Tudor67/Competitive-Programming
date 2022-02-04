class Solution {
public:
    vector<vector<int>> highestRankedKItems(vector<vector<int>>& a, vector<int>& pricing, vector<int>& start, int k) {
        static const vector<pair<int, int>> DIRECTIONS = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        static const int INF = 1e9;
        
        const int ROWS = a.size();
        const int COLS = a[0].size();
        
        int lower = pricing[0];
        int upper = pricing[1];
        
        int startRow = start[0];
        int startCol = start[1];
        
        vector<vector<int>> dist(ROWS, vector<int>(COLS, INF));
        queue<pair<int, int>> q;
        q.emplace(startRow, startCol);
        dist[startRow][startCol] = 0;
        
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            for(const pair<int, int>& DIRECTION: DIRECTIONS){
                int nextRow = row + DIRECTION.first;
                int nextCol = col + DIRECTION.second;
                if(0 <= nextRow && nextRow < ROWS && 0 <= nextCol && nextCol < COLS &&
                   a[nextRow][nextCol] != 0 && dist[row][col] + 1 < dist[nextRow][nextCol]){
                    q.emplace(nextRow, nextCol);
                    dist[nextRow][nextCol] = dist[row][col] + 1;
                }
            }
        }
        
        vector<tuple<int, int, int, int>> v;
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                if(lower <= a[row][col] && a[row][col] <= upper && dist[row][col] != INF){
                    v.emplace_back(dist[row][col], a[row][col], row, col);
                }
            }
        }
        
        sort(v.begin(), v.end());
        
        const int ANSWER_SIZE = min(k, (int)v.size());
        vector<vector<int>> answer(ANSWER_SIZE, vector<int>(2));
        for(int i = 0; i < ANSWER_SIZE; ++i){
            int row = get<2>(v[i]);
            int col = get<3>(v[i]);
            answer[i][0] = row;
            answer[i][1] = col;
        }
        
        return answer;
    }
};