class Solution {
private:
    bool collinear(const vector<int>& p1, const vector<int>& p2, const vector<int>& p3){
        // sarrus rule
        int s1 = p1[0] * p2[1] + p2[0] * p3[1] + p3[0] * p1[1];
        int s2 = p2[1] * p3[0] + p3[1] * p1[0] + p1[1] * p2[0];
        return (s1 == s2);
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