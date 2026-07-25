class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        const int N = nums.size();
        const int Q = queries.size();
        const int MAX_NUM = *max_element(nums.begin(), nums.end());

        vector<int> freq(MAX_NUM + 1);
        for(int num: nums){
            freq[num] += 1;
        }

        vector<long long> gcdPairs(MAX_NUM + 1);
        for(int g = MAX_NUM; g >= 1; --g){
            long long multiples = 0;
            for(int multiple = g; multiple <= MAX_NUM; multiple += g){
                multiples += freq[multiple];
            }
            gcdPairs[g] = (multiples - 1) * multiples / 2;
            for(int multiple = 2 * g; multiple <= MAX_NUM; multiple += g){
                gcdPairs[g] -= gcdPairs[multiple];
            }
        }

        vector<long long> gcdPairsPrefSum = gcdPairs;
        for(int g = 1; g <= MAX_NUM; ++g){
            gcdPairsPrefSum[g] += gcdPairsPrefSum[g - 1];
        }

        vector<int> res(Q);
        for(int i = 0; i < Q; ++i){
            res[i] = upper_bound(gcdPairsPrefSum.begin(), gcdPairsPrefSum.end(), queries[i])
                     - gcdPairsPrefSum.begin();
        }

        return res;
    }
};