class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        const int N = intervals.size();

        bool insertedMergedInterval = false;
        vector<int> mergedInterval = newInterval;
        vector<vector<int>> res;

        for(const vector<int>& I: intervals){
            if(insertedMergedInterval || I[1] < mergedInterval[0]){
                res.push_back(I);
            }else if(mergedInterval[1] < I[0]){
                res.push_back(mergedInterval);
                res.push_back(I);
                insertedMergedInterval = true;
            }else{
                mergedInterval[0] = min(mergedInterval[0], I[0]);
                mergedInterval[1] = max(mergedInterval[1], I[1]);
            }
        }

        if(!insertedMergedInterval){
            res.push_back(mergedInterval);
        }

        return res;
    }
};