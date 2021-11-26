class Robot {
private:
    const vector<pair<int, int>> DIRECTIONS = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    const vector<string> DIRECTIONS_STR = {"East", "North", "West", "South"};
    const int ROWS;
    const int COLS;
    const int CYCLE_STEPS;
    int idx;
    bool madeFirstStep;
    
    tuple<int, int, int> getRowColDir(){
        int row = 0;
        int col = 0;
        int directionIdx = 0;
        if(idx <= COLS - 1){
            row = 0;
            col = idx;
            directionIdx = 0;
            if(madeFirstStep && row == 0 && col == 0){
                directionIdx = (int)DIRECTIONS.size() - 1;
            }
        }else if(idx <= COLS + ROWS - 2){
            row = idx - (COLS - 1);
            col = COLS - 1;
            directionIdx = 1;
        }else if(idx <= 2 * COLS + ROWS - 3){
            row = ROWS - 1;
            col = 2 * COLS + ROWS - 3 - idx;
            directionIdx = 2;
        }else{
            row = CYCLE_STEPS - idx;
            col = 0;
            directionIdx = 3;
        }
        return {row, col, directionIdx};
    }
    
public:
    Robot(int width, int height): ROWS(height), COLS(width), CYCLE_STEPS(2 * height + 2 * width - 4) {
        idx = 0;
        madeFirstStep = false;
    }
    
    void step(int num) {
        idx = (idx + num) % CYCLE_STEPS;
        madeFirstStep = true;
    }
    
    vector<int> getPos() {
        int row, col;
        tie(row, col, ignore) = getRowColDir();
        return {col, row};
    }
    
    string getDir() {
        int directionIdx;
        tie(ignore, ignore, directionIdx) = getRowColDir();
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