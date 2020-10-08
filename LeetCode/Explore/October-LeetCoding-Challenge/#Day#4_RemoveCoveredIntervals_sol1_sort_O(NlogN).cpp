class Solution {
private:
    static bool comp(const vector<int>& LHS, const vector<int>& RHS){
        return (LHS.front() < RHS.front() || (LHS.front() == RHS.front() && LHS.back() > RHS.back()));
    }
    
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), comp);
        
        int answer = 1;
        int intervalEnd = intervals[0][1];
        for(int i = 1; i < intervals.size(); ++i){
            if(intervalEnd < intervals[i][1]){
                answer += 1;
                intervalEnd = intervals[i][1];
            }
        }
        
        return answer;
    }
};