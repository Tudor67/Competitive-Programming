class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        const int N = nums.size();
        int answer = INT_MAX;
        
        if(!nums.empty()){
            vector<long long> prefSum(N);
            prefSum[0] = nums[0];
            for(int i = 1; i < N; ++i){
                prefSum[i] = nums[i] + prefSum[i - 1];
            }
            
            for(int i = 0; i < N; ++i){
                int leftPos = upper_bound(prefSum.begin(), prefSum.end(), prefSum[i] - s) - prefSum.begin();
                long long currentSum = prefSum[i] - (leftPos == 0 ? 0 : prefSum[leftPos - 1]);
                if(currentSum >= s){
                    answer = min(i - leftPos + 1, answer);
                }
            }
        }
        
        if(answer == INT_MAX){
            answer = 0;
        }
        
        return answer;
    }
};