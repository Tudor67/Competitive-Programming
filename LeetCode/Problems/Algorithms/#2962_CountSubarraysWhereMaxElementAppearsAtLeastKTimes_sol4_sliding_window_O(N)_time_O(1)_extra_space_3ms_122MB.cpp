class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        const int N = nums.size();
        const int MAX_NUM = *max_element(nums.begin(), nums.end());

        long long validSubarrays = 0;

        int l = 0;
        int maxNumFreq = 0;
        for(int r = 0; r < N; ++r){
            maxNumFreq += (int)(nums[r] == MAX_NUM);
            while(maxNumFreq - (int)(nums[l] == MAX_NUM) >= k){
                maxNumFreq -= (int)(nums[l] == MAX_NUM);
                l += 1;
            }
            
            if(maxNumFreq >= k){
                validSubarrays += (l + 1);
            }
        }

        return validSubarrays;
    }
};