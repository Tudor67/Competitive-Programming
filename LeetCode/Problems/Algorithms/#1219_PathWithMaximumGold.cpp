class Solution {
private:
    const vector<pair<short int, short int>> D_XY = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    
    void back(short int x, short int y, int sum, stack<int>& st, vector<vector<int>>& grid, int& sol){
        sol = max(sum, sol);
        for(pair<short int, short int> d: D_XY){
            short int next_x = x + d.first;
            short int next_y = y + d.second;
            bool valid = (next_x >= 0 && next_x < grid.size() &&
                          next_y >= 0 && next_y < grid[next_x].size() &&
                          grid[next_x][next_y] > 0);
            if(valid){
                st.push(grid[next_x][next_y]);
                grid[next_x][next_y] = 0;        // mark (next_x, next_y) as a visited position
                back(next_x, next_y, sum + st.top(), st, grid, sol);
                grid[next_x][next_y] = st.top(); // unmark (next_x, next_y)
                st.pop();
            }
        }
    }
    
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        stack<int> st;
        int sol = 0;
        
        for(short int x = 0; x < grid.size(); ++x){
            for(short int y = 0; y < grid[x].size(); ++y){
                if(grid[x][y] > 0){
                    st.push(grid[x][y]);
                    grid[x][y] = 0;
                    back(x, y, st.top(), st, grid, sol);
                    grid[x][y] = st.top();
                    st.pop();
                }
            }
        }
        
        return sol;
    }
};