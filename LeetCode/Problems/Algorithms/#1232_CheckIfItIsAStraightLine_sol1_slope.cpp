class Solution {
private:
    double get_slope(const vector<int>& p1, const vector<int>& p2){
        double dx = p1[0] - p2[0];
        double dy = p1[1] - p2[1];
        double slope = (dy == 0 ? LLONG_MAX : dx / dy);
        return slope;
    }
    
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        double fixed_slope = get_slope(coordinates[0], coordinates[1]);
        bool is_straight_line = true;
        for(int i = 2; i < coordinates.size(); ++i){
            if(fixed_slope != get_slope(coordinates[0], coordinates[i])){
                is_straight_line = false;
            }
        }
        return is_straight_line;
    }
};