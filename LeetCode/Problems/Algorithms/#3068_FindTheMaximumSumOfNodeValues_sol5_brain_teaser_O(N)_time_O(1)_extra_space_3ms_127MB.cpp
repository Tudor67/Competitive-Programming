class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        const int N = nums.size();
        const long long INF = 1e16;
        const long long NUMS_SUM = accumulate(nums.begin(), nums.end(), (long long)0);

        long long res = NUMS_SUM;
        long long countOfPositiveXORContribs = 0;
        long long minPositiveXORContrib = INF;
        long long maxNegativeXORContrib = -INF;
        for(int i = 0; i < N; ++i){
            long long xorContrib = (nums[i] ^ k) - nums[i];
            if(xorContrib >= 0){
                countOfPositiveXORContribs += 1;
                minPositiveXORContrib = min(minPositiveXORContrib, xorContrib);
                res += xorContrib;
            }else{
                maxNegativeXORContrib = max(maxNegativeXORContrib, xorContrib);
            }
        }

        if(countOfPositiveXORContribs % 2 == 1){
            if(maxNegativeXORContrib + minPositiveXORContrib >= 0){
                res += maxNegativeXORContrib;
            }else{
                res -= minPositiveXORContrib;
            }
        }

        return res;
    }
};