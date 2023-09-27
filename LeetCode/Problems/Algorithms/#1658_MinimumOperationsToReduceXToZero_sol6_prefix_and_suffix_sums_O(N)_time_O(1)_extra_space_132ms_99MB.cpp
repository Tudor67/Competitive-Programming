class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        const int N = nums.size();
        const int INF = 1e9;

        int minOps = INF;
        int prefSum = 0;
        int suffSum = accumulate(nums.begin(), nums.end(), 0);

        int j = 0;
        for(int i = -1; i < N; ++i){
            if(i >= 0){
                prefSum += nums[i];
            }

            // prefSum = nums[0] + nums[1] + ... + nums[i]
            // suffSum = nums[j] + nums[j + 1] + ... + nums[N - 1]
            // such that (i < j)
            while(j < N && (prefSum + suffSum > x || i >= j)){
                suffSum -= nums[j];
                j += 1;
            }

            if(prefSum + suffSum == x){
                minOps = min(minOps, i + 1 + N - j);
            }
        }

        if(minOps == INF){
            minOps = -1;
        }

        return minOps;
    }
};