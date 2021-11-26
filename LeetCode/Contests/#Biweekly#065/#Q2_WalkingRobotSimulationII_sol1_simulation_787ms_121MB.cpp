class Robot {
private:
    const vector<pair<int, int>> DIRECTIONS = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    const vector<string> DIRECTIONS_STR = {"East", "North", "West", "South"};
    const int ROWS;
    const int COLS;
    const int CYCLE_STEPS;
    int row;
    int col;
    int directionIdx;
    
public:
    Robot(int width, int height): ROWS(height), COLS(width), CYCLE_STEPS(2 * height + 2 * width - 4) {
        row = 0;
        col = 0;
        directionIdx = 0;
    }
    
    void step(int num) {
        num = num % CYCLE_STEPS;
        if(num == 0){
            num = CYCLE_STEPS;
        }
        while(num > 0){
            int nextRow = row + DIRECTIONS[directionIdx].first;
            int nextCol = col + DIRECTIONS[directionIdx].second;
            if(0 <= nextRow && nextRow < ROWS && 0 <= nextCol && nextCol < COLS){
                row = nextRow;
                col = nextCol;
                num -= 1;
            }else{
                directionIdx = (directionIdx + 1) % DIRECTIONS.size();
            }
        }
    }
    
    vector<int> getPos() {
        return {col, row};
    }
    
    string getDir() {
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