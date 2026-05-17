class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();
        const int LAYERS = min(ROWS, COLS) / 2;

        vector<vector<int>> res(ROWS, vector<int>(COLS));

        vector<int> v;
        for(int layer = 0; layer < LAYERS; ++layer){
            v.clear();

            for(int col = layer; col < COLS - layer; ++col){
                v.push_back(grid[layer][col]);
            }
            for(int row = layer + 1; row < ROWS - layer; ++row){
                v.push_back(grid[row][COLS - 1 - layer]);
            }
            for(int col = COLS - 2 - layer; col >= layer; --col){
                v.push_back(grid[ROWS - 1 - layer][col]);
            }
            for(int row = ROWS - 2 - layer; row >= layer + 1; --row){
                v.push_back(grid[row][layer]);
            }

            int layerSize = v.size();
            int index = k % layerSize;

            for(int col = layer; col < COLS - layer; ++col){
                res[layer][col] = v[index];
                index = (index + 1) % layerSize;
            }
            for(int row = layer + 1; row < ROWS - layer; ++row){
                res[row][COLS - 1 - layer] = v[index];
                index = (index + 1) % layerSize;
            }
            for(int col = COLS - 2 - layer; col >= layer; --col){
                res[ROWS - 1 - layer][col] = v[index];
                index = (index + 1) % layerSize;
            }
            for(int row = ROWS - 2 - layer; row >= layer + 1; --row){
                res[row][layer] = v[index];
                index = (index + 1) % layerSize;
            }
        }

        return res;
    }
};