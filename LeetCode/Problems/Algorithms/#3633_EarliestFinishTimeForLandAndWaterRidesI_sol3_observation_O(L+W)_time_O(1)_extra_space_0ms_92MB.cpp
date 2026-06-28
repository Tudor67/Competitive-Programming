class Solution {
private:
    int computeMinTime(const vector<int>& A_START_TIME, const vector<int>& A_DURATION,
                       const vector<int>& B_START_TIME, const vector<int>& B_DURATION){
        int minFinish1 = INT_MAX;
        for(int i = 0; i < (int)A_START_TIME.size(); ++i){
            minFinish1 = min(minFinish1, A_START_TIME[i] + A_DURATION[i]);
        }

        int minFinish2 = INT_MAX;
        for(int i = 0; i < (int)B_START_TIME.size(); ++i){
            minFinish2 = min(minFinish2, max(minFinish1, B_START_TIME[i]) + B_DURATION[i]);
        }

        return minFinish2;
    }

public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        return min(computeMinTime(landStartTime, landDuration, waterStartTime, waterDuration),
                   computeMinTime(waterStartTime, waterDuration, landStartTime, landDuration));
    }
};