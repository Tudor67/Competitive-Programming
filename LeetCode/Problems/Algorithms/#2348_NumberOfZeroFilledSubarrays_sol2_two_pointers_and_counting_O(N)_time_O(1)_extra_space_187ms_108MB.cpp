class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        const int N = nums.size();

        long long res = 0;
        
        int l = 0;
        while(l < N){
            while(l < N && nums[l] != 0){
                l += 1;
            }

            int r = l;
            while(r < N && nums[r] == 0){
                r += 1;
            }

            long long len = r - l;
            res += len * (len + 1) / 2;

            l = r;
        }

        return res;
    }
};