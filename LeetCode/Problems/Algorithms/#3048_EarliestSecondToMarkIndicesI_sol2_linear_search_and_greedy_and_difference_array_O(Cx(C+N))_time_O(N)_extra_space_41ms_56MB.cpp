class Solution {
private:
    bool isPossible(vector<int>& nums, vector<int>& changeIndices, const int MAX_TIME){
        const int N = nums.size();
        const int C = changeIndices.size();
        const int INF = 1e9;

        int markedIndices = 0;
        long long remOps = 0;
        vector<int> markTimeOf(N + 1, INF);
        for(int t = MAX_TIME; t >= 1; --t){
            remOps = max((long long)0, remOps - 1);
            if(markTimeOf[changeIndices[t - 1]] == INF){
                markTimeOf[changeIndices[t - 1]] = t;
                markedIndices += 1;
                remOps += 1;
                remOps += nums[changeIndices[t - 1] - 1];
            }
        }

        return (markedIndices == N && remOps <= 1);
    }

public:
    int earliestSecondToMarkIndices(vector<int>& nums, vector<int>& changeIndices) {
        const int N = nums.size();
        const int C = changeIndices.size();

        for(int maxTime = N; maxTime <= C; ++maxTime){
            if(isPossible(nums, changeIndices, maxTime)){
                return maxTime;
            }
        }

        return -1;
    }
};