class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        const int N = nums.size();

        vector<int> res(N);
        res[0] = nums[0];
        res[N - 1] = nums[1];

        int l = 0;
        int r = N - 1;
        for(int i = 2; i < N; ++i){
            if(res[l] > res[r]){
                res[++l] = nums[i];
            }else{
                res[--r] = nums[i];
            }
        }
        
        reverse(res.begin() + r, res.end());

        return res;
    }
};