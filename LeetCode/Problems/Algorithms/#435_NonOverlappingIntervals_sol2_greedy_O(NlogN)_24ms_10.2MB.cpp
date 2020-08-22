class Solution {
private:
    static bool comp(const vector<int>& LHS, const vector<int>& RHS){
        return (LHS[1] < RHS[1]);
    }
    
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int answer = 0;
        
        if(!intervals.empty()){
            const int N = intervals.size();
            sort(intervals.begin(), intervals.end(), comp);
            
            int non_overlapping = 1;
            int last_end = intervals[0][1];
            for(const vector<int>& INTERVAL: intervals){
                if(last_end <= INTERVAL[0]){
                    non_overlapping += 1;
                    last_end = INTERVAL[1];
                }
            }
            
            answer = N - non_overlapping;
        }
        
        return answer;
    }
};