class Solution {
private:
    bool is_overlapping(const vector<int>& I1, const vector<int>& I2){
        return (max(I1.front(), I2.front()) <= min(I1.back(), I2.back()));
    }
    
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        const int N = intervals.size();
        vector<vector<int>> answer;
        
        int first_overlap = N;
        int last_overlap = -1;
        for(int i = 0; i < N; ++i){
            if(is_overlapping(intervals[i], newInterval)){
                newInterval[0] = min(intervals[i][0], newInterval[0]);
                newInterval[1] = max(intervals[i][1], newInterval[1]);
                first_overlap = min(i, first_overlap);
                last_overlap = max(i, last_overlap);
            }
        }
        
        if(first_overlap <= last_overlap){
            answer.resize(N - (last_overlap - first_overlap));
            copy(intervals.begin(), intervals.begin() + first_overlap + 1, answer.begin());
            answer[first_overlap] = newInterval;
            copy(intervals.begin() + last_overlap + 1, intervals.end(), answer.begin() + first_overlap + 1);
        }else{
            int pos = 0;
            for(int i = 0; i <= N; ++i){
                if(i == N || newInterval.back() < intervals[i].front()){
                    pos = i;
                    break;
                }
            }
            answer.resize(N + 1);
            copy(intervals.begin(), intervals.begin() + pos, answer.begin());
            answer[pos] = newInterval;
            copy(intervals.begin() + pos, intervals.end(), answer.begin() + pos + 1);
        }
        
        return answer;
    }
};