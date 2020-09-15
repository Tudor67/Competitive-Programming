class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        const int N = intervals.size();
        vector<vector<int>> answer;
        answer.reserve(N + 1);
        
        bool inserted = false;
        for(int i = 0; !inserted && i < N; ++i){
            if(intervals[i].back() < newInterval.front()){
                answer.push_back(intervals[i]);
            }else if(newInterval.back() < intervals[i].front()){
                answer.push_back(newInterval);
                copy(intervals.begin() + i, intervals.end(), back_inserter(answer));
                inserted = true;
            }else{
                newInterval[0] = min(intervals[i][0], newInterval[0]);
                newInterval[1] = max(intervals[i][1], newInterval[1]);
            }
        }
        
        if(!inserted){
            answer.push_back(newInterval);
        }
        
        return answer;
    }
};