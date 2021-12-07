class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        const int N = nums.size();
        const int M = 2 * k + 1;
        
        vector<int> avgs(N, -1);
        
        long long sum = 0;
        for(int i = 0; i < N; ++i){
            sum += nums[i];
            if(i - M >= 0){
                sum -= nums[i - M];
            }
            if(i - M + 1 >= 0){
                avgs[i - M / 2] = sum / M;
            }
        }
        
        return avgs;
    }
};