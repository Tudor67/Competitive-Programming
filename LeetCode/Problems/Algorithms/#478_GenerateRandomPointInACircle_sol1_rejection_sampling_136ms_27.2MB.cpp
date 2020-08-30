class Solution {
private:
    double r;
    double xc, yc;
    
public:
    Solution(double radius, double x_center, double y_center) {
        r = radius;
        xc = x_center;
        yc = y_center;
    }
    
    vector<double> randPoint() {
        double x;
        double y;
        do{
            x = xc - r + 2.0 * r * (rand() / (double)RAND_MAX);
            y = yc - r + 2.0 * r * (rand() / (double)RAND_MAX);
        }while(pow(xc - x, 2) + pow(yc - y, 2) > pow(r, 2));
        return {x, y};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */