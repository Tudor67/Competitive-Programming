class Solution {
private:
    void back(int level, int maxLevel, int sum, int target, vector<int>& nums, unordered_map<int, int>& count){
        if(level == maxLevel + 1){
            count[sum] += 1;
        }else{
            back(level + 1, maxLevel, sum - nums[level], target, nums, count);
            back(level + 1, maxLevel, sum + nums[level], target, nums, count);
        }
    }
    
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        const int N = nums.size();
        
        // sums from first half
        unordered_map<int, int> count1;
        back(0, N / 2, 0, target, nums, count1);
        
        // sums from second half
        unordered_map<int, int> count2;
        back(N / 2 + 1, N - 1, 0, target, nums, count2);
        
        // combine sums from first and second half
        int res = 0;
        for(const pair<int, int>& P1: count1){
            int sum1 = P1.first;
            int sum2 = target - sum1;
            if(count2.count(sum2)){
                res += count1[sum1] * count2[sum2];
            }
        }
        
        return res;
    }
};