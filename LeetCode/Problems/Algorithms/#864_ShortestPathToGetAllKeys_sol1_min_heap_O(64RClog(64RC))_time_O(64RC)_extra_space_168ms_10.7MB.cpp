struct State{
    int cost;
    int keysMask;
    int row;
    int col;
    
    State(int cost, int keysMask, int row, int col){
        this->cost = cost;
        this->keysMask = keysMask;
        this->row = row;
        this->col = col;
    }
    
    State(){
        State(INT_MAX, 0, -1, -1);
    }
};

struct MinHeapStateComparator{
    bool operator()(const State& LHS, const State& RHS){
        return (LHS.cost > RHS.cost);
    }
};

class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();
        
        // Step 1: fix startRow, startCol, minKey and maxKey
        int startRow = -1;
        int startCol = -1;
        char maxKey = 'a';
        for(int row = 0; row < ROWS; ++row){
            for(int col = 0; col < COLS; ++col){
                if(grid[row][col] == '@'){
                    startRow = row;
                    startCol = col;
                }else if(islower(grid[row][col]) && grid[row][col] > maxKey){
                    maxKey = grid[row][col];
                }
            }
        }
        
        const char MIN_KEY = 'a';
        const char MAX_KEY = maxKey;
        const int KEYS_CNT = MAX_KEY - MIN_KEY + 1;
        const int MAX_KEYS_MASK = (1 << KEYS_CNT) - 1;
        
        // Step 2: define minCost
        vector<vector<vector<int>>> minCost(ROWS, vector<vector<int>>(COLS, vector<int>(MAX_KEYS_MASK + 1, INT_MAX)));
        minCost[startRow][startCol][0] = 0;
        
        // Step 3: define minHeap
        priority_queue<State, vector<State>, MinHeapStateComparator> minHeap;
        minHeap.push(State(0, 0, startRow, startCol));
        
        // Step 4: search all the keys using the minHeap of all states (similar with Dijkstra's algorithm)
        const vector<pair<int, int>> DIRECTIONS = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        while(!minHeap.empty()){
            State state = minHeap.top();
            minHeap.pop();
            
            for(const pair<int, int>& DIRECTION: DIRECTIONS){
                int nextRow = state.row + DIRECTION.first;
                int nextCol = state.col + DIRECTION.second;
                if(nextRow >= 0 && nextRow < ROWS && nextCol >= 0 && nextCol < COLS && grid[nextRow][nextCol] != '#'){
                    int nextKeysMask = state.keysMask;
                    if(islower(grid[nextRow][nextCol])){
                        nextKeysMask |= (1 << (grid[nextRow][nextCol] - MIN_KEY));
                    }
                    
                    if(isupper(grid[nextRow][nextCol])){
                        int pos = tolower(grid[nextRow][nextCol]) - MIN_KEY;
                        if(!(state.keysMask & (1 << pos))){
                            // nextPos is locked and we do not have the corresponding key in state.keysMask
                            continue;
                        }
                    }
                    
                    int nextCost = minCost[nextRow][nextCol][nextKeysMask];
                    if(minCost[state.row][state.col][state.keysMask] + 1 < nextCost){
                        nextCost = minCost[state.row][state.col][state.keysMask] + 1;
                        minCost[nextRow][nextCol][nextKeysMask] = nextCost;
                        minHeap.push(State(nextCost, nextKeysMask, nextRow, nextCol));
                        if(nextKeysMask == MAX_KEYS_MASK){
                            return nextCost;
                        }
                    }
                }
            }
        }
        
        return -1;
    }
};

/*
Testcases:
["@.a.#","###.#","b.A.B"]
["@..aA","..B#.","....b"]
["@..aA","...#B","....b"]
["@..aA",".###B",".b.cC"]
[".@B.a",".A###","..bcC"]
["C@B.a",".A###","..bcC"]
*/