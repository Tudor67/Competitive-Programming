class Solution {
private:
    const vector<pair<int, int>> DIRECTIONS = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    
    bool is_valid(const vector<vector<char>>& board, const int& I, const int& J,
                  vector<vector<bool>>& vis){
        int min_line = I;
        int max_line = I;
        int min_col = J;
        int max_col = J;
        
        queue<pair<int, int>> q;
        q.push({I, J});
        vis[I][J] = true;
        
        while(!q.empty()){
            int line = q.front().first;
            int col = q.front().second;
            q.pop();
            
            min_line = min(line, min_line);
            max_line = max(line, max_line);
            min_col = min(col, min_col);
            max_col = max(col, max_col);
            
            for(const pair<int, int>& DIRECTION: DIRECTIONS){
                int new_line = line + DIRECTION.first;
                int new_col = col + DIRECTION.second;
                if(new_line >= 0 && new_line < (int)board.size() &&
                   new_col >= 0 && new_col < (int)board[0].size() &&
                   board[new_line][new_col] == 'O' &&
                   !vis[new_line][new_col]){
                    q.push({new_line, new_col});
                    vis[new_line][new_col] = true;
                }
            }
        }
        
        return (min_line > 0 && max_line < (int)board.size() - 1 &&
                min_col > 0 && max_col < (int)board[0].size() - 1);
    }
    
    void fill(vector<vector<char>>& board, const int& I, const int& J){
        queue<pair<int, int>> q;
        q.push({I, J});
        board[I][J] = 'X';
        
        while(!q.empty()){
            int line = q.front().first;
            int col = q.front().second;
            q.pop();
            
            for(const pair<int, int>& DIRECTION: DIRECTIONS){
                int new_line = line + DIRECTION.first;
                int new_col = col + DIRECTION.second;
                if(new_line >= 0 && new_line < (int)board.size() &&
                   new_col >= 0 && new_col < (int)board[0].size() &&
                   board[new_line][new_col] == 'O'){
                    q.push({new_line, new_col});
                    board[new_line][new_col] = 'X';
                }
            }
        }
    }
    
public:
    void solve(vector<vector<char>>& board) {
        if(board.empty()){
            return;
        }
        
        const int N = board.size();
        const int M = board[0].size();
        vector<vector<bool>> vis(N, vector<bool>(M, false));
        
        for(int i = 0; i < N; ++i){
            for(int j = 0; j < M; ++j){
                if(board[i][j] == 'O' && !vis[i][j]){
                    if(is_valid(board, i, j, vis)){
                        fill(board, i, j);
                    }
                }
            }
        }
    }
};