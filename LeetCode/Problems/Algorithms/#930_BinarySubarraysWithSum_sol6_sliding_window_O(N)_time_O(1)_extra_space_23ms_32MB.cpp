class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        const int N = nums.size();

        int res = 0;

        int sum = 0;
        int lPrefZeros = 0;
        int l = 0;
        for(int r = 0; r < N; ++r){
            sum += nums[r];
            while(l < r && (nums[l] == 0 || sum > goal)){
                if(nums[l] == 0){
                    lPrefZeros += 1;
                }else{
                    lPrefZeros = 0;
                }
                sum -= nums[l];
                l += 1;
            }

            if(sum == goal){
                res += (1 + lPrefZeros);
            }
        }

        return res;
    }
};