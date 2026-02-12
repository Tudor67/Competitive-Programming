class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        const int N = nums.size();

        vector<int> res(N);
        for(int i = 0; i < N; ++i){
            res[i] = nums[((i + nums[i]) % N + N) % N];
        }

        return res;
    }
};