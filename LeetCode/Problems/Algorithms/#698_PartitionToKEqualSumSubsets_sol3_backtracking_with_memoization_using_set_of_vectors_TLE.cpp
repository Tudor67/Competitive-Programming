class Solution {
private:
    set<vector<int>> memo;
    
    void solve(int level, vector<int>& sums, const int& EXPECTED_SUM, const vector<int>& NUMS, const int& K, bool& partitionFound){
        if(level == NUMS.size()){
            bool isValidPartition = true;
            for(int subsetIdx = 0; subsetIdx < K; ++subsetIdx){
                if(sums[subsetIdx] != EXPECTED_SUM){
                    isValidPartition = false;
                }
            }
            partitionFound = isValidPartition;
        }else{
            for(int subsetIdx = 0; subsetIdx < K; ++subsetIdx){
                if(!partitionFound && sums[subsetIdx] + NUMS[level] <= EXPECTED_SUM){
                    sums[subsetIdx] += NUMS[level];
                    vector<int> subsetSumState(sums.begin(), sums.end());
                    sort(subsetSumState.begin(), subsetSumState.end());
                    if(!memo.count(subsetSumState)){
                        memo.insert(subsetSumState);
                        solve(level + 1, sums, EXPECTED_SUM, NUMS, K, partitionFound);
                    }
                    sums[subsetIdx] -= NUMS[level];
                }
            }
        }
    }
    
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        const int TOTAL_SUM = accumulate(nums.begin(), nums.end(), 0);
        const int EXPECTED_SUM = TOTAL_SUM / k;
        memo.clear();
        vector<int> sums(k, 0);
        bool partitionFound = false;
        solve(0, sums, EXPECTED_SUM, nums, k, partitionFound);
        return partitionFound;
    }
};