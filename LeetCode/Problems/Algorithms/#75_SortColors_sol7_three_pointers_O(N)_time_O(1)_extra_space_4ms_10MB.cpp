class Solution {
public:
    void sortColors(vector<int>& nums) {
        const int N = nums.size();

        // We maintain the following invariant when processing nums[i]:
        // nums[0 .. l - 1] contains only zeros
        // nums[l .. i - 1] contains only ones
        // nums[i] is being processed
        // nums[i + 1 .. r] is not processed yet
        // nums[r + 1 .. N - 1] contains only twos

        int l = 0;
        int r = N - 1;
        int i = 0;
        while(i <= r){
            if(nums[i] == 0){
                swap(nums[l], nums[i]);
                l += 1;
                i += 1;
            }else if(nums[i] == 1){
                i += 1;
            }else{
                swap(nums[i], nums[r]);
                r -= 1;
            }
        }
    }
};