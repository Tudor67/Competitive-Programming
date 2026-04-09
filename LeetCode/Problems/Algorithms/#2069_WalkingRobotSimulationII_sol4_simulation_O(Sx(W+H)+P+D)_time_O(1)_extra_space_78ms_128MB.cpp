class Robot {
private:
    const vector<pair<int, int>> DIRECTIONS = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    const vector<string> DIRECTIONS_STR = {"East", "North", "West", "South"};
    int width;
    int height;
    int cycleSize;
    int x;
    int y;
    int dirIndex;

    bool isInside(int x, int y){
        return (0 <= x && x < width && 0 <= y && y < height);
    }

public:
    Robot(int width, int height) {
        this->width = width;
        this->height = height;
        this->cycleSize = 2 * (width + height - 2);
        this->x = 0;
        this->y = 0;
        this->dirIndex = 0;
    }
    
    void step(int num) {
        num %= cycleSize;
        if(num == 0){
            num = cycleSize;
        }
        for(int i = 0; i < num; ++i){
            if(!isInside(x + DIRECTIONS[dirIndex].first, y + DIRECTIONS[dirIndex].second)){
                dirIndex = (dirIndex + 1) % DIRECTIONS.size();
            }
            x += DIRECTIONS[dirIndex].first;
            y += DIRECTIONS[dirIndex].second;
        }
    }
    
    vector<int> getPos() {
        return {x, y};
    }
    
    string getDir() {
        return DIRECTIONS_STR[dirIndex];
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */