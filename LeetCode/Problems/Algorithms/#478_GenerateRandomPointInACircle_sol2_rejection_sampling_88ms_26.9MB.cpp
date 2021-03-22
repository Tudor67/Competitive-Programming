class Solution {
private:
    double radius;
    double xCenter;
    double yCenter;
    
public:
    Solution(double radius, double xCenter, double yCenter) {
        this->radius = radius;
        this->xCenter = xCenter;
        this->yCenter = yCenter;
        srand(time(NULL));
    }
    
    vector<double> randPoint() {
        double dx;
        double dy;
        do{
            int dxSign = (rand() % 2 == 0 ? -1 : 1);
            int dySign = (rand() % 2 == 0 ? -1 : 1);
            dx = radius * dxSign * rand() / (double)(RAND_MAX);
            dy = radius * dySign * rand() / (double)(RAND_MAX);
        }while(dx * dx + dy * dy > radius * radius);
        return {xCenter + dx, yCenter + dy};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */