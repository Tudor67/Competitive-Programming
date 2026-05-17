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
            int topRow = layer;
            int leftCol = layer;
            int bottomRow = ROWS - 1 - layer;
            int rightCol = COLS - 1 - layer;

            for(int col = leftCol; col < rightCol; ++col){
                v.push_back(grid[topRow][col]);
            }
            for(int row = topRow; row < bottomRow; ++row){
                v.push_back(grid[row][rightCol]);
            }
            for(int col = rightCol; col > leftCol; --col){
                v.push_back(grid[bottomRow][col]);
            }
            for(int row = bottomRow; row > topRow; --row){
                v.push_back(grid[row][leftCol]);
            }

            int layerSize = v.size();
            int index = k % layerSize;

            for(int col = leftCol; col < rightCol; ++col){
                res[topRow][col] = v[index];
                index = (index + 1) % layerSize;
            }
            for(int row = topRow; row < bottomRow; ++row){
                res[row][rightCol] = v[index];
                index = (index + 1) % layerSize;
            }
            for(int col = rightCol; col > leftCol; --col){
                res[bottomRow][col] = v[index];
                index = (index + 1) % layerSize;
            }
            for(int row = bottomRow; row > topRow; --row){
                res[row][leftCol] = v[index];
                index = (index + 1) % layerSize;
            }
        }

        return res;
    }
};