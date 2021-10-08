class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        const int N = nums.size();
        vector<int> duplicates;
        for(int i = 0; i < N; ++i){
            int pos = abs(nums[i]) - 1;
            if(nums[pos] < 0){
                duplicates.push_back(abs(nums[i]));
            }
            // mark as visited
            nums[pos] = -nums[pos];
        }
        for(int i = 0; i < N; ++i){
            nums[i] = abs(nums[i]);
        }
        return duplicates;
    }
};