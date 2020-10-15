class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.empty()){
            return 0;
        }
        
        sort(points.begin(), points.end());
        
        int answer = 1;
        int xEnd = points[0][1];
        for(int i = 1; i < points.size(); ++i){
            if(xEnd < points[i][0]){
                xEnd = points[i][1];
                answer += 1;
            }
            xEnd = min(points[i][1], xEnd);
        }
        
        return answer;
    }
};