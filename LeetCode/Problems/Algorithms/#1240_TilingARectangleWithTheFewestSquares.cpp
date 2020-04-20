class Solution {
private:
    short int n;
    short int m;
    vector<vector<bool>> vis;
    
    void fill(const short int& line, const short int& col, const short int& len, const bool& val){
        for(short int i = line; i < line + len; ++i){
            for(short int j = col; j < col + len; ++j){
                vis[i][j] = val;
            }
        }
    }
    
    short int get_max_sq_len(const short int& line, const short int& col){
        for(short int dx = 0; dx < min(n, m); ++dx){
            bool ok = (line + dx < n && col + dx < m && !vis[line + dx][col] && !vis[line][col + dx]);
            if(!ok){
                return dx;
            }
        }
        return min(n - line, m - col);
    }
    
    pair<short int, short int> get_next_unvis_pos(const short int& line){
        for(short int i = line; i < n; ++i){
            for(short int j = 0; j < m; ++j){
                if(!vis[i][j]){
                    return {i, j};
                }
            }
        }
        return {n, m};
    }
    
    void back(short int k, const short int& line, const short int& col, short int& ans){
        if(line == n && col == m){
            ans = min(k, ans);
        }else if(k < ans){
            short int max_sq_len = get_max_sq_len(line, col);
            for(short int len = max_sq_len; len >= 1; --len){
                fill(line, col, len, 1);
                pair<short int, short int> next_pos = get_next_unvis_pos(line);
                back(k + 1, next_pos.first, next_pos.second, ans);
                fill(line, col, len, 0);
            }
        }
    }
    
public:
    int tilingRectangle(int n, int m) {
        this->n = n;
        this->m = m;
        this->vis.resize(n, vector<bool>(m, false));
        
        short int ans = n * m;
        back(0, 0, 0, ans);
        
        return ans;
    }
};