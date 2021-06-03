class Solution {
private:
    unordered_set<int> memo;
    
    void solve(int remainingSubsets, int currentSum, const int& EXPECTED_SUM, const vector<int>& NUMS, int usedMask, bool& partitionFound){
        if(remainingSubsets == 0){
            partitionFound |= (currentSum == 0 && __builtin_popcount(usedMask) == NUMS.size());
        }else{
            for(int i = 0; i < NUMS.size(); ++i){
                int nextUsedMask = usedMask | (1 << i);
                if(!partitionFound && !(usedMask & (1 << i)) && !memo.count(nextUsedMask)){
                    if(currentSum + NUMS[i] < EXPECTED_SUM){
                        memo.insert(nextUsedMask);
                        solve(remainingSubsets, currentSum + NUMS[i], EXPECTED_SUM, NUMS, nextUsedMask, partitionFound);
                    }else if(currentSum + NUMS[i] == EXPECTED_SUM){
                        memo.insert(nextUsedMask);
                        solve(remainingSubsets - 1, 0, EXPECTED_SUM, NUMS, nextUsedMask, partitionFound);
                    }
                }
            }
        }
    }
    
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        const int TOTAL_SUM = accumulate(nums.begin(), nums.end(), 0);
        const int EXPECTED_SUM = TOTAL_SUM / k;
        memo.clear();
        bool partitionFound = false;
        solve(k, 0, EXPECTED_SUM, nums, 0, partitionFound);
        return partitionFound;
    }
};