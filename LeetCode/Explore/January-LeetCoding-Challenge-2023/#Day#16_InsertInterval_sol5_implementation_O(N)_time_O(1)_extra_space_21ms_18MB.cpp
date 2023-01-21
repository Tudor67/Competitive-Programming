class Solution {
private:
    bool intersects(const vector<int>& A, const vector<int>& B){
        return (max(A[0], B[0]) <= min(A[1], B[1]));
    }

    vector<int> mergeIntervals(const vector<int>& A, const vector<int>& B){
        return {min(A[0], B[0]), max(A[1], B[1])};
    }

public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        const int N = intervals.size();

        vector<int> mergedInterval = newInterval;
        for(const vector<int>& I: intervals){
            if(intersects(I, mergedInterval)){
                mergedInterval = mergeIntervals(I, mergedInterval);
            }
        }

        vector<vector<int>> res;
        for(const vector<int>& I: intervals){
            if(I[1] < mergedInterval[0]){
                res.push_back(I);
            }
        }

        res.push_back(mergedInterval);

        for(const vector<int>& I: intervals){
            if(mergedInterval[1] < I[0]){
                res.push_back(I);
            }
        }

        return res;
    }
};