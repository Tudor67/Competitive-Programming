class Solution {
public:
    void sortColors(vector<int>& nums) {
        const int N = nums.size();
        vector<int> idx(3, -1);
        for(int num: nums){
            if(num == 0){
                nums[++idx[2]] = 2;
                nums[++idx[1]] = 1;
                nums[++idx[0]] = 0;
            }else if(num == 1){
                nums[++idx[2]] = 2;
                nums[++idx[1]] = 1;
            }else if(num == 2){
                nums[++idx[2]] = 2;
            }
        }
    }
};