class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> answer;
        sort(intervals.begin(), intervals.end());
        for(const vector<int>& INTERVAL: intervals){
            if(answer.empty() || answer.back()[1] < INTERVAL[0]){
                answer.push_back(INTERVAL);
            }else{
                answer.back()[1] = max(answer.back()[1], INTERVAL[1]);
            }
        }
        return answer;
    }
};