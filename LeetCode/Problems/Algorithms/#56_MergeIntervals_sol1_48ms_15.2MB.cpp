class Solution {
private:
    vector<int> intersection(const vector<int>& I1, const vector<int>& I2){
        int l = max(I1[0], I2[0]);
        int r = min(I1[1], I2[1]);
        return {l, r};
    }
    
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> answer;
        
        if(!intervals.empty()){
            sort(intervals.begin(), intervals.end());
            
            vector<int> currentInterval = intervals[0];
            for(int i = 0; i < intervals.size(); ++i){
                vector<int> intersectionInterval = intersection(currentInterval, intervals[i]);
                if(intersectionInterval[0] <= intersectionInterval[1]){
                    currentInterval[1] = max(currentInterval[1], intervals[i][1]);
                }else{
                    answer.push_back(currentInterval);
                    currentInterval = intervals[i];
                }
            }
            
            if(answer.empty() || answer.back() != currentInterval){
                answer.push_back(currentInterval);
            }
        }
        
        return answer;
    }
};