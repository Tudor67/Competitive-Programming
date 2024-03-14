class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        const int N = nums.size();

        int res = 0;

        int sum = 0;
        int i = 0;
        int j = 0;
        for(int k = 0; k < N; ++k){
            sum += nums[k];
            while(sum > goal){
                sum -= nums[i];
                i += 1;
            }

            j = max(j, i);
            while(j < k && nums[j] == 0){
                j += 1;
            }

            if(i <= k && sum == goal){
                res += (j - i + 1);
            }
        }

        return res;
    }
};