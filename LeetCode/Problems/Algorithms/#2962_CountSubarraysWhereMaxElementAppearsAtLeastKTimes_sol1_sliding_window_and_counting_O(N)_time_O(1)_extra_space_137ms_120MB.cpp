class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        const int N = nums.size();
        const int MAX_NUM = *max_element(nums.begin(), nums.end());

        long long res = 0;
        int maxNumFreq = 0;
        int l = 0;

        for(int r = 0; r < N; ++r){
            maxNumFreq += (int)(nums[r] == MAX_NUM);
            while(l <= r && (nums[l] != MAX_NUM || maxNumFreq > k)){
                maxNumFreq -= (int)(nums[l] == MAX_NUM);
                l += 1;
            }
            if(maxNumFreq == k){
                res += (l + 1);
            }
        }

        return res;
    }
};