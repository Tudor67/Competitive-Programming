class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        const int N = points.size();
        
        sort(points.begin(), points.end());
        
        int arrows = 1;
        int xEndMin = points[0][1];
        for(const vector<int>& P: points){
            int xStart = P[0];
            int xEnd = P[1];
            if(xEndMin < xStart){
                arrows += 1;
                xEndMin = xEnd;
            }else{
                xEndMin = min(xEndMin, xEnd);
            }
        }
        
        return arrows;
    }
};