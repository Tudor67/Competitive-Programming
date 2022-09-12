class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        const int N = nums.size();
        
        long long sum = 0;
        long long weightedSum = 0;
        for(int i = 1; i < N; ++i){
            sum += nums[i];
            weightedSum += i * nums[i];
        }
        
        long long res = weightedSum;
        for(int i = N; i < 2 * N - 1; ++i){
            weightedSum -= sum;
            weightedSum += (N - 1) * nums[i - N];
            sum -= nums[i - N + 1];
            sum += nums[i - N];
            res = max(res, weightedSum);
        }
        
        return res;
    }
};