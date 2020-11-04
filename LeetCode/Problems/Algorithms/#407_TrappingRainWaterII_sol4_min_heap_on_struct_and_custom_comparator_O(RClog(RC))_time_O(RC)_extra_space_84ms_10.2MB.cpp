struct Cell{
    int height;
    int row;
    int col;

    Cell(int height, int row, int col){
        this->height = height;
        this->row = row;
        this->col = col;
    }
};

struct MinHeapCellComparator{
    bool operator()(const Cell& LHS, const Cell& RHS){
        return (LHS.height > RHS.height);
    }
};

class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        const int ROWS = heightMap.size();
        const int COLS = heightMap[0].size();
        const vector<pair<int, int>> DIRECTIONS = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        priority_queue<Cell, vector<Cell>, MinHeapCellComparator> minHeap;
        vector<vector<bool>> vis(ROWS, vector<bool>(COLS, false));
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                if(row == 0 || row == ROWS - 1 || col == 0 || col == COLS - 1){
                    minHeap.push(Cell(heightMap[row][col], row, col));
                    vis[row][col] = true;
                }
            }
        }
        
        int answer = 0;
        while(!minHeap.empty()){
            Cell cell = minHeap.top();
            minHeap.pop();
            
            for(const pair<int, int>& DIRECTION: DIRECTIONS){
                int nextRow = cell.row + DIRECTION.first;
                int nextCol = cell.col + DIRECTION.second;
                if(nextRow >= 0 && nextRow < ROWS && nextCol >= 0 && nextCol < COLS && !vis[nextRow][nextCol]){
                    answer += max(0, cell.height - heightMap[nextRow][nextCol]);
                    Cell nextCell(max(cell.height, heightMap[nextRow][nextCol]), nextRow, nextCol);
                    minHeap.push(nextCell);
                    vis[nextRow][nextCol] = true;
                }
            }
        }
        
        return answer;
    }
};