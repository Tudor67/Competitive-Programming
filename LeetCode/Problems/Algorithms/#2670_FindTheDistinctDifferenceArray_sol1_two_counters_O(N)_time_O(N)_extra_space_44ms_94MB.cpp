class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        const int N = nums.size();
        
        unordered_map<int, int> prefCount;
        unordered_map<int, int> suffCount;
        for(int num: nums){
            suffCount[num] += 1;
        }
        
        vector<int> res(N);
        for(int i = 0; i < N; ++i){
            prefCount[nums[i]] += 1;
            suffCount[nums[i]] -= 1;
            if(suffCount[nums[i]] == 0){
                suffCount.erase(nums[i]);
            }
            res[i] = (int)prefCount.size() - (int)suffCount.size();
        }
        
        return res;
    }
};