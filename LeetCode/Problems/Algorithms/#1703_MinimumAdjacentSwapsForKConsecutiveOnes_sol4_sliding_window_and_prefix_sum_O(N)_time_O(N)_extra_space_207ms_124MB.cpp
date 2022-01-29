class Solution {
private:
    long long computeRangeSum(vector<long long>& prefSum, int l, int r){
        if(l == 0){
            return prefSum[r];
        }
        return prefSum[r] - prefSum[l - 1];
    }
    
public:
    int minMoves(vector<int>& nums, int k) {
        const int N = nums.size();
        
        if(k == 1 || k == N){
            return 0;
        }
        
        vector<int> onePositions;
        for(int i = 0; i < N; ++i){
            if(nums[i] == 1){
                onePositions.push_back(i);
            }
        }
        
        const int M = onePositions.size();
        vector<long long> prefSum(M);
        prefSum[0] = onePositions[0];
        for(int i = 1; i < M; ++i){
            prefSum[i] = prefSum[i - 1] + onePositions[i];
        }
        
        long long answer = LLONG_MAX;
        for(int i = k - 1; i < M; ++i){
            long long rangeSum1 = computeRangeSum(prefSum, i - k + 1, i - k + k / 2);
            long long rangeSum2 = computeRangeSum(prefSum, i - k / 2 + 1, i);
            long long cost = (rangeSum2 - rangeSum1) - (k / 2) * (k / 2 + 1LL) + ((k + 1) % 2) * (k / 2);
            answer = min(answer, cost);
        }
        
        return answer;
    }
};