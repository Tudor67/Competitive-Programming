class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        const int L = landStartTime.size();
        const int W = waterStartTime.size();

        int res = INT_MAX;
        for(int i = 0; i < L; ++i){
            for(int j = 0; j < W; ++j){
                int t1 = max(landStartTime[i] + landDuration[i], waterStartTime[j]) + waterDuration[j];
                int t2 = max(waterStartTime[j] + waterDuration[j], landStartTime[i]) + landDuration[i];
                int t = min(t1, t2);
                res = min(res, t);
            }
        }

        return res;
    }
};