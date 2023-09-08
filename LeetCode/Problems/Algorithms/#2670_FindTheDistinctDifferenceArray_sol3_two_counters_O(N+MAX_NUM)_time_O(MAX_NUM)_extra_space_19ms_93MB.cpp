class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        const int N = nums.size();
        const int MAX_NUM = *max_element(nums.begin(), nums.end());
        
        vector<int> prefCount(MAX_NUM + 1);
        int prefUnique = 0;

        vector<int> suffCount(MAX_NUM + 1);
        int suffUnique = 0;
        
        for(int num: nums){
            suffCount[num] += 1;
            suffUnique += (int)(suffCount[num] == 1);
        }
        
        vector<int> res(N);
        for(int i = 0; i < N; ++i){
            prefCount[nums[i]] += 1;
            prefUnique += (int)(prefCount[nums[i]] == 1);
            suffCount[nums[i]] -= 1;
            suffUnique -= (int)(suffCount[nums[i]] == 0);
            res[i] = prefUnique - suffUnique;
        }
        
        return res;
    }
};