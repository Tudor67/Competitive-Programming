class Robot {
private:
    int width;
    int height;
    int cycleSize;
    int pos;
    bool hasMoved;

public:
    Robot(int width, int height) {
        this->width = width;
        this->height = height;
        this->cycleSize = 2 * (width + height - 2);
        this->pos = 0;
        this->hasMoved = false;
    }
    
    void step(int num) {
        pos = (pos + num) % cycleSize;
        hasMoved = true;
    }
    
    vector<int> getPos() {
        if(pos < width){
            return {pos, 0};
        }
        if(pos < width + height - 1){
            return {width - 1, pos - (width - 1)};
        }
        if(pos < 2 * width + height - 2){
            return {cycleSize - (height - 1) - pos, height - 1};
        }
        return {0, cycleSize - pos};
    }
    
    string getDir() {
        if(pos == 0){
            if(hasMoved){
                return "South";
            }
            return "East";
        }
        if(pos < width){
            return "East";
        }
        if(pos < width + height - 1){
            return "North";
        }
        if(pos < 2 * width + height - 2){
            return "West";
        }
        return "South";
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */