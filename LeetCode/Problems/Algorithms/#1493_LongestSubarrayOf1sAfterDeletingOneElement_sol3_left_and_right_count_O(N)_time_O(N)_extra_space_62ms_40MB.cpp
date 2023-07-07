class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        const int N = nums.size();

        if(N <= 1){
            return 0;
        }

        vector<int> lMaxLen(N);
        lMaxLen[0] = nums[0];
        for(int i = 1; i < N; ++i){
            if(nums[i] == 0){
                lMaxLen[i] = 0;
            }else{
                lMaxLen[i] = lMaxLen[i - 1] + 1;
            }
        }

        vector<int> rMaxLen(N);
        rMaxLen[N - 1] = nums[N - 1];
        for(int i = N - 2; i >= 0; --i){
            if(nums[i] == 0){
                rMaxLen[i] = 0;
            }else{
                rMaxLen[i] = 1 + rMaxLen[i + 1];
            }
        }

        int res = 0;
        for(int i = 0; i < N; ++i){
            int len = 0;
            if(i >= 1){
                len += lMaxLen[i - 1];
            }
            if(i <= N - 2){
                len += rMaxLen[i + 1];
            }
            res = max(res, len);
        }

        return res;
    }
};