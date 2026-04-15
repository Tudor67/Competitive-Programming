class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        const int N = nums.size();
        const int Q = queries.size();
        const int MODULO = 1'000'000'007;

        vector<int> coeffs(N, 1);
        for(const vector<int>& QUERY: queries){
            int l = QUERY[0];
            int r = QUERY[1];
            int k = QUERY[2];
            int v = QUERY[3];

            for(int i = l; i <= r; i += k){
                coeffs[i] = coeffs[i] * (long long)v % MODULO;
            }
        }

        int resXOR = 0;
        for(int i = 0; i < N; ++i){
            int num = nums[i] * (long long)coeffs[i] % MODULO;
            resXOR ^= num;
        }

        return resXOR;
    }
};