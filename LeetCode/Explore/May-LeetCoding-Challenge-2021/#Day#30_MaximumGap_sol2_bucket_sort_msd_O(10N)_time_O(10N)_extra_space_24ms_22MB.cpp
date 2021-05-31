class Solution {
private:
    void bucketSort(vector<int>& nums, int pow10 = 1e9){
        if(nums.empty() || pow10 == 0){
            return;
        }
        vector<vector<int>> buckets(10);
        for(int num: nums){
            buckets[(num / pow10) % 10].push_back(num);
        }
        nums.clear();
        for(int bucketId = 0; bucketId < (int)buckets.size(); ++bucketId){
            bucketSort(buckets[bucketId], pow10 / 10);
            for(int num: buckets[bucketId]){
                nums.push_back(num);
            }
        }
    }
    
public:
    int maximumGap(vector<int>& nums) {
        bucketSort(nums);
        
        int maxGap = 0;
        for(int i = 1; i < (int)nums.size(); ++i){
            maxGap = max(maxGap, nums[i] - nums[i - 1]);
        }
        
        return maxGap;
    }
};