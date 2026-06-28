class Solution {
private:
    int computeMinTime(const vector<int>& A_START_TIME, const vector<int>& A_DURATION,
                       const vector<int>& B_START_TIME, const vector<int>& B_DURATION){
        const int A_SIZE = A_START_TIME.size();
        const int B_SIZE = B_START_TIME.size();

        vector<pair<int, int>> B(B_SIZE);
        for(int i = 0; i < B_SIZE; ++i){
            B[i] = {B_START_TIME[i], B_DURATION[i]};
        }

        sort(B.begin(), B.end());

        vector<int> bDurationPrefMin(B_SIZE);
        bDurationPrefMin[0] = B[0].second;
        for(int i = 1; i < B_SIZE; ++i){
            bDurationPrefMin[i] = min(bDurationPrefMin[i - 1], B[i].second);
        }

        vector<int> bEndTimeSuffMin(B_SIZE);
        bEndTimeSuffMin[B_SIZE - 1] = B[B_SIZE - 1].first + B[B_SIZE - 1].second;
        for(int i = B_SIZE - 2; i >= 0; --i){
            bEndTimeSuffMin[i] = min(B[i].first + B[i].second, bEndTimeSuffMin[i + 1]);
        }

        int minTime = INT_MAX;
        for(int i = 0; i < A_SIZE; ++i){
            int aEndTime = A_START_TIME[i] + A_DURATION[i];

            int l = 0;
            int r = B_SIZE;
            while(l != r){
                int mid = (l + r) / 2;
                if(B[mid].first <= aEndTime){
                    l = mid + 1;
                }else{
                    r = mid;
                }
            }

            if(r - 1 >= 0){
                minTime = min(minTime, aEndTime + bDurationPrefMin[r - 1]);
            }
            if(r < B_SIZE){
                minTime = min(minTime, bEndTimeSuffMin[r]);
            }
        }

        return minTime;
    }

public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        return min(computeMinTime(landStartTime, landDuration, waterStartTime, waterDuration),
                   computeMinTime(waterStartTime, waterDuration, landStartTime, landDuration));
    }
};