class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        const int N = intervals.size();

        vector<vector<int>> res;
        vector<int> mergedInterval = newInterval;
        bool insertedMergedInterval = false;

        for(int i = 0; i < N && !insertedMergedInterval; ++i){
            if(intervals[i][1] < mergedInterval[0]){
                res.push_back(intervals[i]);
            }else if(mergedInterval[1] < intervals[i][0]){
                res.push_back(mergedInterval);
                copy(intervals.begin() + i, intervals.end(), back_inserter(res));
                insertedMergedInterval = true;
            }else{
                mergedInterval[0] = min(mergedInterval[0], intervals[i][0]);
                mergedInterval[1] = max(mergedInterval[1], intervals[i][1]);
            }
        }

        if(!insertedMergedInterval){
            res.push_back(mergedInterval);
        }

        return res;
    }
};