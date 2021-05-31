class Solution {
public:
    int maximumGap(vector<int>& nums) {
        const int INF = 1e9;
        const int N = nums.size();
        const int MIN_ELEM = *min_element(nums.begin(), nums.end());
        const int MAX_ELEM = *max_element(nums.begin(), nums.end());
        
        if(MIN_ELEM == MAX_ELEM){
            return 0;
        }
        
        if(N == 1){
            return 0;
        }
        
        if(N == 2){
            return abs(nums[0] - nums[1]);
        }
        
        vector<pair<int, int>> bucketsMinMax(N, {INF, -INF});
        for(int num: nums){
            int bucketIdx = (num - MIN_ELEM) * (N - 1LL) / (MAX_ELEM - MIN_ELEM + 1);
            const pair<int, int>& P = bucketsMinMax[bucketIdx];
            bucketsMinMax[bucketIdx] = {min(P.first, num), max(P.second, num)};
        }
        
        int maxGap = 0;
        int prevValidBucketIdx = 0;
        for(int bucketIdx = 0; bucketIdx < N; ++bucketIdx){
            if(bucketsMinMax[bucketIdx].first != INF){
                if(bucketsMinMax[prevValidBucketIdx].first != INF){
                    int gap = bucketsMinMax[bucketIdx].first - bucketsMinMax[prevValidBucketIdx].second;
                    maxGap = max(gap, maxGap);
                }
                prevValidBucketIdx = bucketIdx;
            }
        }
        
        return maxGap;
    }
};