class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        const int N = nums.size();

        vector<int> avgs(N, -1);
        
        long long sum = 0;
        for(int i = 0; i < N; ++i){
            sum += nums[i];
            if(i >= 2 * k + 1){
                sum -= nums[i - (2 * k + 1)];
            }
            if(i >= 2 * k){
                avgs[i - k] = sum / (2 * k + 1);
            }
        }

        return avgs;
    }
};