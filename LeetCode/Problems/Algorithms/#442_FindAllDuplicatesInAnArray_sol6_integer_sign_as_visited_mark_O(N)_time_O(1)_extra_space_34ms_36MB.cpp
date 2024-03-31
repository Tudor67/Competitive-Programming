class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        const int N = nums.size();

        vector<int> duplicates;
        for(int i = 0; i < N; ++i){
            int index = abs(nums[i]) - 1;
            if(nums[index] < 0){
                duplicates.push_back(abs(nums[i]));
            }else{
                nums[index] = -nums[index];
            }
        }

        for(int i = 0; i < N; ++i){
            if(nums[i] < 0){
                nums[i] = -nums[i];
            }
        }

        return duplicates;
    }
};