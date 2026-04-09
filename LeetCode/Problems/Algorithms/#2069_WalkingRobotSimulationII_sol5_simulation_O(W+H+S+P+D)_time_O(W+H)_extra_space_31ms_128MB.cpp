class Robot {
private:
    const vector<pair<int, int>> DIRECTIONS = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    const vector<string> DIRECTIONS_STR = {"East", "North", "West", "South"};
    int cycleSize;
    bool robotMoved;
    vector<array<int, 3>> states;
    int stateIndex;

    bool isInside(int x, int y, int width, int height){
        return (0 <= x && x < width && 0 <= y && y < height);
    }

public:
    Robot(int width, int height) {
        cycleSize = 2 * (width + height - 2);
        robotMoved = false;
        stateIndex = 0;
        states.reserve(cycleSize);

        int x = 0;
        int y = 0;
        int dirIndex = 0;
        states.push_back({x, y, 3});

        for(int i = 1; i < cycleSize; ++i){
            if(!isInside(x + DIRECTIONS[dirIndex].first, y + DIRECTIONS[dirIndex].second, width, height)){
                dirIndex = (dirIndex + 1) % DIRECTIONS.size();
            }
            x += DIRECTIONS[dirIndex].first;
            y += DIRECTIONS[dirIndex].second;
            states.push_back({x, y, dirIndex});
        }
    }
    
    void step(int num) {
        stateIndex = (stateIndex + num) % cycleSize;
        robotMoved = true;
    }
    
    vector<int> getPos() {
        return {states[stateIndex][0], states[stateIndex][1]};
    }
    
    string getDir() {
        if(robotMoved){
            return DIRECTIONS_STR[states[stateIndex][2]];
        }
        return DIRECTIONS_STR[0];
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */