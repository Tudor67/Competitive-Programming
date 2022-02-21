class Solution {
private:
    static bool incStartDecEndComp(const vector<int>& LHS, const vector<int>& RHS){
        return (LHS[0] < RHS[0] || (LHS[0] == RHS[0] && LHS[1] > RHS[1]));
    }
    
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        const int N = intervals.size();
        
        sort(intervals.begin(), intervals.end(), incStartDecEndComp);
        
        int covered = 0;
        int maxEnd = intervals[0][1];
        for(int i = 1; i < N; ++i){
            if(maxEnd >= intervals[i][1]){
                covered += 1;
            }
            maxEnd = max(maxEnd, intervals[i][1]);
        }
        
        return N - covered;
    }
};