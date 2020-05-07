class Solution {
private:
    const vector<pair<int, int>> DIRECTIONS = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    
    void dfs(int line, int col, vector<vector<bool>>& vis,
             int& min_line, int& max_line, int& min_col, int& max_col){
        vis[line][col] = true;
        
        min_line = min(line, min_line);
        max_line = max(line, max_line);
        min_col = min(col, min_col);
        max_col = max(col, max_col);
        
        for(const pair<int, int>& direction: DIRECTIONS){
            int new_line = line + direction.first;
            int new_col = col + direction.second;
            
            if(new_line >= 0 && new_line <= (int)vis.size() - 1 &&
               new_col >= 0 && new_col <= (int)vis[0].size() - 1 &&
               !vis[new_line][new_col]){
                dfs(new_line, new_col, vis, min_line, max_line, min_col, max_col);
            }
        }
    }

    void fill(int line, int col, vector<vector<char>>& board){
        board[line][col] = 'X';
        
        for(const pair<int, int>& direction: DIRECTIONS){
            int new_line = line + direction.first;
            int new_col = col + direction.second;
            
            if(new_line >= 0 && new_line <= (int)board.size() - 1 &&
               new_col >= 0 && new_col <= (int)board[0].size() - 1 &&
               board[new_line][new_col] == 'O'){
                fill(new_line, new_col, board);
            }
        }
    }
    
public:
    void solve(vector<vector<char>>& board) {
        if(board.empty()){
            return;
        }
        
        vector<vector<bool>> vis(board.size(), vector<bool>(board[0].size(), false));
        for(int i = 0; i < board.size(); ++i){
            for(int j = 0; j < board[0].size(); ++j){
                if(board[i][j] == 'X'){
                    vis[i][j] = true;
                }
            }
        }
        
        for(int i = 0; i < board.size(); ++i){
            for(int j = 0; j < board[0].size(); ++j){
                if(!vis[i][j]){
                    int min_line = i;
                    int max_line = i;
                    int min_col = j;
                    int max_col = j;
                    
                    dfs(i, j, vis, min_line, max_line, min_col, max_col);
                    
                    if(min_line > 0 && max_line < (int)board.size() - 1 &&
                       min_col > 0 && max_col < (int)board[0].size() - 1){
                        fill(i, j, board);
                    }
                }
            }
        }
    }
};