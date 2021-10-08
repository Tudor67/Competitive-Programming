class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        const int N = nums.size();
        for(int i = 0; i < N; ++i){
            while(nums[i] != nums[nums[i] - 1]){
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        vector<int> duplicates;
        for(int i = 0; i < N; ++i){
            if(i + 1 != nums[i]){
                duplicates.push_back(nums[i]);
            }
        }
        return duplicates;
    }
};