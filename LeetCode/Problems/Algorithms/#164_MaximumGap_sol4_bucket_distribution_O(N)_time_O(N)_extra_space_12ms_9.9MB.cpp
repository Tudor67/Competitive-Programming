class Solution {
public:
    int maximumGap(vector<int>& nums) {
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
        
        vector<vector<int>> buckets(N);
        for(int num: nums){
            int bucketIdx = (num - MIN_ELEM) * (N - 1LL) / (MAX_ELEM - MIN_ELEM + 1);
            buckets[bucketIdx].push_back(num);
        }
        
        int maxGap = 0;
        int prevValidBucketIdx = 0;
        for(int bucketIdx = 0; bucketIdx < N; ++bucketIdx){
            if(!buckets[bucketIdx].empty()){
                if(!buckets[prevValidBucketIdx].empty()){
                    int gap = *min_element(buckets[bucketIdx].begin(), buckets[bucketIdx].end()) -
                              *max_element(buckets[prevValidBucketIdx].begin(), buckets[prevValidBucketIdx].end());
                    maxGap = max(gap, maxGap);
                }
                prevValidBucketIdx = bucketIdx;
            }
        }
        
        return maxGap;
    }
};