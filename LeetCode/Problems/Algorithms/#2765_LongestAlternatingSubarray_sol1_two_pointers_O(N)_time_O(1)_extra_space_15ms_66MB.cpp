class Solution {
public:
    int alternatingSubarray(vector<int>& nums) {
        const int N = nums.size();

        int maxLen = -1;

        int i = 0;
        while(i + 1 < N){
            if(nums[i + 1] - nums[i] == 1){
                int j = i + 1;
                while(j + 1 < N && nums[j] - nums[j - 1] == -(nums[j + 1] - nums[j])){
                    j += 1;
                }
                maxLen = max(maxLen, j - i + 1);
                i = j;
            }else{
                i += 1;
            }
        }

        return maxLen;
    }
};