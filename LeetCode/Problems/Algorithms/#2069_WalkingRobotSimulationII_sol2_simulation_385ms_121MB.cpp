class Robot {
private:
    const vector<pair<int, int>> DIRECTIONS = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    const vector<string> DIRECTIONS_STR = {"East", "North", "West", "South"};
    const int ROWS;
    const int COLS;
    const int CYCLE_STEPS;
    vector<tuple<int, int, int>> rowColDir;
    int idx;
    bool madeFirstStep;
    
public:
    Robot(int width, int height): ROWS(height), COLS(width), CYCLE_STEPS(2 * height + 2 * width - 4) {
        rowColDir.resize(CYCLE_STEPS);
        idx = 0;
        madeFirstStep = false;
        
        int row = 0;
        int col = 0;
        int directionIdx = 0;
        int currentStep = 0;
        while(currentStep < CYCLE_STEPS){
            rowColDir[currentStep] = {row, col, directionIdx};
            int nextRow = row + DIRECTIONS[directionIdx].first;
            int nextCol = col + DIRECTIONS[directionIdx].second;
            if(0 <= nextRow && nextRow < ROWS && 0 <= nextCol && nextCol < COLS){
                row = nextRow;
                col = nextCol;
                currentStep += 1;
            }else{
                directionIdx = (directionIdx + 1) % DIRECTIONS.size();
            }
        }
    }
    
    void step(int num) {
        idx = (idx + num) % CYCLE_STEPS;
        madeFirstStep = true;
    }
    
    vector<int> getPos() {
        int row, col;
        tie(row, col, ignore) = rowColDir[idx];
        return {col, row};
    }
    
    string getDir() {
        int row, col, directionIdx;
        tie(row, col, directionIdx) = rowColDir[idx];
        if((row == 0 || row == ROWS - 1) && (col == 0 || col == COLS - 1)){
            directionIdx = (directionIdx - 1 + (int)DIRECTIONS.size()) % DIRECTIONS.size();
        }
        if(!madeFirstStep){
            directionIdx = 0;
        }
        return DIRECTIONS_STR[directionIdx];
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */