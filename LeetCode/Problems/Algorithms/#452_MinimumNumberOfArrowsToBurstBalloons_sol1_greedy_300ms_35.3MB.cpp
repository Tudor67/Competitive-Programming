class Solution {
private:
    static bool comp(const vector<int>& LHS, const vector<int>& RHS){
        return (LHS[0] < RHS[0]) || (LHS[0] == RHS[0] && LHS[1] > RHS[1]);
    }
    
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.empty()){
            return 0;
        }
        
        sort(points.begin(), points.end(), comp);
        
        int answer = 1;
        int xEnd = points[0][1];
        for(int i = 0; i < points.size(); ++i){
            if(xEnd < points[i][0]){
                xEnd = points[i][1];
                answer += 1;
            }
            xEnd = min(points[i][1], xEnd);
        }
        
        return answer;
    }
};