class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();
        const int LAYERS = min(ROWS, COLS) / 2;

        vector<vector<int>> res(ROWS, vector<int>(COLS));

        vector<int> v;
        vector<pair<int, int>> coords;
        for(int layer = 0; layer < LAYERS; ++layer){
            v.clear();
            coords.clear();
            int topRow = layer;
            int leftCol = layer;
            int bottomRow = ROWS - 1 - layer;
            int rightCol = COLS - 1 - layer;

            for(int col = leftCol; col < rightCol; ++col){
                v.push_back(grid[topRow][col]);
                coords.push_back({topRow, col});
            }
            for(int row = topRow; row < bottomRow; ++row){
                v.push_back(grid[row][rightCol]);
                coords.push_back({row, rightCol});
            }
            for(int col = rightCol; col > leftCol; --col){
                v.push_back(grid[bottomRow][col]);
                coords.push_back({bottomRow, col});
            }
            for(int row = bottomRow; row > topRow; --row){
                v.push_back(grid[row][leftCol]);
                coords.push_back({row, leftCol});
            }

            int layerSize = v.size();
            for(int i = 0; i < layerSize; ++i){
                res[coords[i].first][coords[i].second] = v[(i + k) % layerSize];
            }
        }

        return res;
    }
};