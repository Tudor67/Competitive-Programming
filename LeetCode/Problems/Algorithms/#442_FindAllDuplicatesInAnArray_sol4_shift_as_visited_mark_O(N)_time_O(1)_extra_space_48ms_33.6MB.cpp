class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        const int N = nums.size();
        const int SHIFT = N + 1;
        vector<int> duplicates;
        for(int i = 0; i < N; ++i){
            int pos = (nums[i] % SHIFT) - 1;
            if(nums[pos] > SHIFT){
                duplicates.push_back(nums[i] % SHIFT);
            }
            // mark as visited
            nums[pos] += SHIFT;
        }
        for(int i = 0; i < N; ++i){
            nums[i] %= SHIFT;
        }
        return duplicates;
    }
};