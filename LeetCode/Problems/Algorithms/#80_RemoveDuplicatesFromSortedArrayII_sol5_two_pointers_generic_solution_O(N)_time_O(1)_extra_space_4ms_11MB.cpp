class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        const int N = nums.size();
        const int K = 2;
        
        int i = K;
        for(int j = K; j < N; ++j){
            if(nums[i - K] != nums[j]){
                nums[i] = nums[j];
                ++i;
            }
        }
        
        return min(i, N);
    }
};