class Solution {
public:
    void sortColors(vector<int>& nums) {
        const int N = nums.size();
        int i = 0; // nums[0 .. i - 1] contains zeros
        int j = 0; // nums[i .. j - 1] contains ones
        int k = N - 1; // nums[k + 1 .. N - 1] contains twos
        while(j <= k){
            if(nums[j] == 0){
                swap(nums[i], nums[j]);
                i += 1;
                j += 1;
            }else if(nums[j] == 1){
                j += 1;
            }else if(nums[j] == 2){
                swap(nums[j], nums[k]);
                k -= 1;
            }
        }
    }
};