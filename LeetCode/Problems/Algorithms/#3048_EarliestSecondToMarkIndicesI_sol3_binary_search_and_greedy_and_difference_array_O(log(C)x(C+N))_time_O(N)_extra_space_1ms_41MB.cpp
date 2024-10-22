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

        if(N > C || !isPossible(nums, changeIndices, C)){
            return -1;
        }

        int l = N;
        int r = C;
        while(l != r){
            int mid = (l + r) / 2;
            if(isPossible(nums, changeIndices, mid)){
                r = mid;
            }else{
                l = mid + 1;
            }
        }

        return r;
    }
};