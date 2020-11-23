class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // Step 1: sort intervals
        sort(intervals.begin(), intervals.end());
        
        // Step 2: merge intervals
        vector<vector<int>> answer;
        answer.push_back(intervals[0]);
        for(int i = 1; i < intervals.size(); ++i){
            if(answer.back().back() >= intervals[i].front()){
                answer.back().back() = max(intervals[i].back(), answer.back().back());
            }else{
                answer.push_back(intervals[i]);
            }
        }
        
        return answer;
    }
};