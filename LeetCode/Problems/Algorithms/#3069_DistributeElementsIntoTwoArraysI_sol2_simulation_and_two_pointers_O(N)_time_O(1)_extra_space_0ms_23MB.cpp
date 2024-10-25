class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        const int N = nums.size();

        int l = 0;
        int r = N - 1;
        vector<int> res(N);
        res[l] = nums[0];
        res[r] = nums[1];

        for(int i = 2; i < N; ++i){
            if(res[l] > res[r]){
                l += 1;
                res[l] = nums[i];
            }else{
                r -= 1;
                res[r] = nums[i];
            }
        }

        reverse(res.begin() + r, res.end());

        return res;
    }
};