class Solution {
private:
    int computeMinTime(const vector<int>& A_START, const vector<int>& A_DURATION,
                       const vector<int>& B_START, const vector<int>& B_DURATION){
        int minFinishA = INT_MAX;
        for(int i = 0; i < (int)A_START.size(); ++i){
            minFinishA = min(minFinishA, A_START[i] + A_DURATION[i]);
        }

        int minFinishB = INT_MAX;
        for(int i = 0; i < (int)B_START.size(); ++i){
            minFinishB = min(minFinishB, max(minFinishA, B_START[i]) + B_DURATION[i]);
        }

        return minFinishB;
    }

public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        return min(computeMinTime(landStartTime, landDuration, waterStartTime, waterDuration),
                   computeMinTime(waterStartTime, waterDuration, landStartTime, landDuration));
    }
};