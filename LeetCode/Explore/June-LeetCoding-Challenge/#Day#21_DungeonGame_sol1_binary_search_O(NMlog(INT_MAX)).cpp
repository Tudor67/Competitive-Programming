class Solution {
private:
    bool is_valid(const vector<vector<int>>& dungeon, const int& INITIAL_HEALTH){
        const vector<pair<int, int>> DIRECTIONS = {{0, 1}, {1, 0}};
        const int N = dungeon.size();
        const int M = dungeon[0].size();
        
        vector<vector<int>> h(N, vector<int>(M, 0));
        h[0][0] = dungeon[0][0] + INITIAL_HEALTH;
        
        if(h[0][0] > 0){
            vector<vector<bool>> in_queue(N, vector<bool>(M, false));
            queue<pair<int, int>> q;
            q.push({0, 0});
            in_queue[0][0] = true;
            
            while(!q.empty() && h[N - 1][M - 1] <= 0){
                int line = q.front().first;
                int col = q.front().second;
                q.pop();
                
                in_queue[line][col] = false;
                
                for(const pair<int, int> DIRECTION: DIRECTIONS){
                    int next_line = line + DIRECTION.first;
                    int next_col = col + DIRECTION.second;
                    if(next_line < N && next_col < M &&
                       h[line][col] + dungeon[next_line][next_col] > h[next_line][next_col]){
                        h[next_line][next_col] = h[line][col] + dungeon[next_line][next_col];
                        if(!in_queue[next_line][next_col]){
                            q.push({next_line, next_col});
                            in_queue[next_line][next_col] = true;
                        }
                    }
                }
            }
        }
        
        return (h[N - 1][M - 1] > 0);
    }
    
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        const int N = dungeon.size();
        const int M = dungeon[0].size();
        
        int min_path_val = dungeon[0][0];
        int sum = 0;
        for(int i = 0; i < N; ++i){
            sum += dungeon[i][0];
            min_path_val = min(sum, min_path_val);
        }
        
        for(int j = 1; j < M; ++j){
            sum += dungeon[N - 1][j];
            min_path_val = min(sum, min_path_val);
        }
        
        int l = max(-dungeon[0][0] + 1, 1);
        int r = max(-min_path_val + 1, 1);
        while(l != r){
            int mid = l + (r - l) / 2;
            if(is_valid(dungeon, mid)){
                r = mid;
            }else{
                l = mid + 1;
            }
        }
        
        return r;
    }
};