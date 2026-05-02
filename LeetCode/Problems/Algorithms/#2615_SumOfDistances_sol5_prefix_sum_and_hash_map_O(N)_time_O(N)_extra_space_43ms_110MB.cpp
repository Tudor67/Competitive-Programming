class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        const int N = nums.size();

        unordered_map<int, vector<int>> numToIndices;
        for(int i = 0; i < N; ++i){
            numToIndices[nums[i]].push_back(i);
        }

        vector<long long> res(N);
        for(const auto& [_, INDICES]: numToIndices){
            long long prefSum = 0;
            long long prefCount = 0;
            long long suffSum = accumulate(INDICES.begin(), INDICES.end(), (long long)0);
            long long suffCount = INDICES.size();

            for(long long i: INDICES){
                res[i] = i * prefCount - prefSum +
                         suffSum - i * suffCount;
                prefSum += i;
                prefCount += 1;
                suffSum -= i;
                suffCount -= 1;
            }
        }

        return res;
    }
};