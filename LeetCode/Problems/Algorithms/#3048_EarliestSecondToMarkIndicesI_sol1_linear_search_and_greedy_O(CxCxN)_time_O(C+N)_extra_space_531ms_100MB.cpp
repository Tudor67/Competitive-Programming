class Solution {
private:
    bool isPossible(vector<int>& nums, vector<int>& changeIndices, const int MAX_TIME){
        const int N = nums.size();
        const int C = changeIndices.size();
        const int INF = 1e9;

        vector<int> markTimeOf(N + 1, INF);
        vector<int> markTimes;
        vector<bool> usedTime(MAX_TIME + 1, false);
        for(int t = MAX_TIME; t >= 1; --t){
            if(markTimeOf[changeIndices[t - 1]] == INF){
                markTimeOf[changeIndices[t - 1]] = t;
                markTimes.push_back(t);
                usedTime[t] = true;
            }
        }
        
        int markedNums = 0;
        for(int markTime: markTimes){
            int remDecOps = nums[changeIndices[markTime - 1] - 1];
            for(int t = markTime; t >= 1 && remDecOps >= 1; --t){
                if(!usedTime[t]){
                    usedTime[t] = true;
                    remDecOps -= 1;
                }
            }

            if(remDecOps == 0){
                markedNums += 1;
            }else{
                break;
            }
        }

        return (markedNums == N);
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