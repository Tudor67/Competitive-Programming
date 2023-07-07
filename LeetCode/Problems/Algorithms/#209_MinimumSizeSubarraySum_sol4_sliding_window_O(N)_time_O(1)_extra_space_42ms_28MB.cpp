class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        const int N = nums.size();
        const int INF = 1e9;

        int minLen = INF;

        int l = 0;
        int sum = 0;
        for(int r = 0; r < N; ++r){
            sum += nums[r];
            while(sum - nums[l] >= target){
                sum -= nums[l];
                l += 1;
            }
            if(sum >= target){
                minLen = min(minLen, r - l + 1);
            }
        }

        if(minLen != INF){
            return minLen;
        }
        
        return 0;
    }
};