class Solution {
private:
    const double EPS = 1e-7;
    
    double dist(const vector<int>& p1, const vector<int>& p2){
        double dx = p1[0] - p2[0];
        double dy = p1[1] - p2[1];
        return sqrt(dx * dx + dy * dy);
    }
    
    bool collinear(const vector<int>& p1, const vector<int>& p2, const vector<int>& p3){
        double d12 = dist(p1, p2);
        double d23 = dist(p2, p3);
        double d13 = dist(p1, p3);
        return (d12 + d23 - d13 < EPS || d12 + d13 - d23 < EPS || d23 + d13 - d12 < EPS);
    }
    
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        bool is_straight_line = true;
        for(int i = 2; i < coordinates.size(); ++i){
            if(!collinear(coordinates[0], coordinates[1], coordinates[i])){
                is_straight_line = false;
            }
        }
        return is_straight_line;
    }
};