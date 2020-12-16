class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        const int K = 2;
        int i = K;
        for(int j = K; j < nums.size(); ++j){
            if(nums[i - K] != nums[j]){
                nums[i++] = nums[j];
            }
        }
        return min((int)nums.size(), i);
    }
};