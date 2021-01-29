class Solution {
private:
    using Matrix2D = vector<vector<int>>;
    using Position = pair<int, int>;
    using Transition = pair<Position, Position>;
    using State = pair<int, Transition>;
    
    vector<State> getNextValidStates(const Position& POS, Matrix2D& minEffort, Matrix2D& heights){
        static const vector<pair<int, int>> DIRECTIONS = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
        const int ROWS = heights.size();
        const int COLS = heights[0].size();
        
        int row = POS.first;
        int col = POS.second;
        vector<State> nextStates;
        for(const pair<int, int>& DIRECTION: DIRECTIONS){
            int nextRow = row + DIRECTION.first;
            int nextCol = col + DIRECTION.second;
            bool isInside = (0 <= nextRow && nextRow < ROWS && 0 <= nextCol && nextCol < COLS);
            if(isInside){
                int localEffort = abs(heights[row][col] - heights[nextRow][nextCol]);
                int globalEffort = max(localEffort, minEffort[row][col]);
                if(globalEffort < minEffort[nextRow][nextCol] || minEffort[nextRow][nextCol] == -1){
                    Position nextPos = {nextRow, nextCol};
                    Transition transition = {POS, nextPos};
                    State state = {globalEffort, transition};
                    nextStates.push_back(state);
                }
            }
        }
        
        return nextStates;
    }
    
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        const int ROWS = heights.size();
        const int COLS = heights[0].size();
        
        Matrix2D minEffort(ROWS, vector<int>(COLS, -1));
        priority_queue<State, vector<State>, greater<State>> minHeap;
        
        minEffort[0][0] = 0;
        Position pos = {0, 0};
        do{
            vector<State> nextValidStates = getNextValidStates(pos, minEffort, heights);
            for(const State& STATE: nextValidStates){
                int effort = STATE.first;
                Transition transition = STATE.second;
                Position nextPos = transition.second;
                int nextRow = nextPos.first;
                int nextCol = nextPos.second;
                if(minEffort[nextRow][nextCol] == -1 || effort < minEffort[nextRow][nextCol]){
                    minEffort[nextRow][nextCol] = effort;
                    minHeap.push(STATE);
                }
            }
            
            if(pos == Position{ROWS - 1, COLS - 1}){
                break;
            }else{
                State state = minHeap.top(); minHeap.pop();
                pos = state.second.second;
            }
        }while(true);
        
        return minEffort[ROWS - 1][COLS - 1];
    }
};