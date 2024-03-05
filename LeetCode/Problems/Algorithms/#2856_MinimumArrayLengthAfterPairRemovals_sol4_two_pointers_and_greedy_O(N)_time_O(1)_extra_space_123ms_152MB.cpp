class Solution {
public:
    int minLengthAfterRemovals(vector<int>& nums) {
        const int N = nums.size();

        int res = N;

        int i = 0;
        int j = N - N / 2;
        while(j < N){
            if(nums[i] == nums[j]){
                j += 1;
            }else{
                i += 1;
                j += 1;
                res -= 2;
            }
        }

        return res;
    }
};