class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        const int N = nums.size();
        
        unordered_map<int, int> count;
        for(int mask = 0; mask <= (1 << (N / 2)) - 1; ++mask){
            int sum = 0;
            for(int bit = 0; bit < N / 2; ++bit){
                if((mask >> bit) & 1){
                    sum += nums[bit];
                }else{
                    sum -= nums[bit];
                }
            }
            count[sum] += 1;
        }
        
        int res = 0;
        for(int mask = 0; mask <= (1 << (N - N / 2)) - 1; ++mask){
            int sum = 0;
            for(int bit = 0; bit < N - N / 2; ++bit){
                if((mask >> bit) & 1){
                    sum += nums[bit + N / 2];
                }else{
                    sum -= nums[bit + N / 2];
                }
            }
            if(count.count(target - sum)){
                res += count[target - sum];
            }
        }
        
        return res;
    }
};