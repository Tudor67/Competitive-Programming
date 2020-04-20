class Solution {
private:
    const vector<pair<int, int>> DISPL_IJ = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
    void back(int k, int i, int j, const int& empty_squares_cnt, vector<vector<int>>& grid, int& ans){
        for(const pair<int, int>& p: DISPL_IJ){
            int next_i = i + p.first;
            int next_j = j + p.second;
            bool is_inside = (next_i >= 0 && next_i < grid.size() &&
                              next_j >= 0 && next_j < grid[next_i].size());
            if(is_inside){
                bool is_visited = (grid[next_i][next_j] != 0);
                bool is_last_pos = (k == empty_squares_cnt);
                bool is_ending_square = (grid[next_i][next_j] == 2);

                if(is_last_pos && is_ending_square){
                    ++ans;
                }else if(!is_visited){
                    int temp = grid[next_i][next_j];
                    grid[next_i][next_j] = -1;
                    back(k + 1, next_i, next_j, empty_squares_cnt, grid, ans);
                    grid[next_i][next_j] = temp;
                }
            }
        }
    }
    
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        pair<int, int> start_pos;
        int empty_squares_cnt = 0;
        for(int i = 0; i < grid.size(); ++i){
            for(int j = 0; j < grid[i].size(); ++j){
                if(grid[i][j] == 0){
                    ++empty_squares_cnt;
                }else if(grid[i][j] == 1){
                    start_pos = {i, j};
                }
            }
        }
        
        int ans = 0;
        back(0, start_pos.first, start_pos.second, empty_squares_cnt, grid, ans);
        
        return ans;
    }
};