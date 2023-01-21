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

        vector<vector<int>> res;
        int i = 0;
        while(i < N && intervals[i][1] <= newInterval[0]){
            res.push_back(intervals[i]);
            i += 1;
        }

        if(!res.empty() && intersects(res.back(), newInterval)){
            res.back() = mergeIntervals(res.back(), newInterval);
        }else{
            res.push_back(newInterval);
        }

        while(i < N){
            if(intersects(res.back(), intervals[i])){
                res.back() = mergeIntervals(res.back(), intervals[i]);
            }else{
                res.push_back(intervals[i]);
            }
            i += 1;
        }

        return res;
    }
};