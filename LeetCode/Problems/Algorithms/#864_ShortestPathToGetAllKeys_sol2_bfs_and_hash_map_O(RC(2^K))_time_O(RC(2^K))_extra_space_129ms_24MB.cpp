struct State {
    int row;
    int col;
    int keysMask;

    State(int row, int col, int keysMask):
          row(row), col(col), keysMask(keysMask) {
    }

    bool operator==(const State& other) const {
        return (this->row == other.row) &&
               (this->col == other.col) &&
               (this->keysMask == other.keysMask);
    }
};

struct StateHash {
    size_t operator()(const State& STATE) const {
        return STATE.row | (STATE.col << 6) | (STATE.keysMask << 12);
    }
};

class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();
        const vector<pair<int, int>> DIRECTIONS = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        const char STARTING_POINT = '@';
        const char WALL = '#';
        const char EMPTY_CELL = '.';

        int startRow = 0;
        int startCol = 0;
        int totalKeys = 0;
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                if(grid[row][col] == STARTING_POINT){
                    startRow = row;
                    startCol = col;
                }else if(islower(grid[row][col])){
                    totalKeys = max(totalKeys, grid[row][col] - 'a' + 1);
                }
            }
        }

        unordered_map<State, int, StateHash> minDist;
        queue<State> q;
        State startState(startRow, startCol, 0);
        minDist[startState] = 0;
        q.push(startState);

        while(!q.empty()){
            State state = q.front();
            q.pop();

            if(__builtin_popcount(state.keysMask) == totalKeys){
                return minDist[state];
            }

            for(const pair<int, int>& DIRECTION: DIRECTIONS){
                int nextRow = state.row + DIRECTION.first;
                int nextCol = state.col + DIRECTION.second;
                if(nextRow >= 0 && nextRow < ROWS && nextCol >= 0 && nextCol < COLS && grid[nextRow][nextCol] != WALL){
                    int nextKeysMask = state.keysMask;
                    if(islower(grid[nextRow][nextCol])){
                        nextKeysMask |= (1 << (grid[nextRow][nextCol] - 'a'));
                    }

                    State nextState(nextRow, nextCol, nextKeysMask);
                    if(!minDist.count(nextState) || minDist[state] + 1 < minDist[nextState]){
                        if(!isupper(grid[nextRow][nextCol]) || ((state.keysMask >> (grid[nextRow][nextCol] - 'A')) & 1)){
                            minDist[nextState] = minDist[state] + 1;
                            q.push(nextState);
                        }
                    }
                }
            }
        }

        return -1;
    }
};