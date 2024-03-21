class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        const int N = nums.size();

        vector<int> res(N, 1);
        for(int i = 1; i < N; ++i){
            res[i] = res[i - 1] * nums[i - 1];
        }

        int suffProd = 1;
        for(int i = N - 2; i >= 0; --i){
            suffProd *= nums[i + 1];
            res[i] *= suffProd;
        }

        return res;
    }
};