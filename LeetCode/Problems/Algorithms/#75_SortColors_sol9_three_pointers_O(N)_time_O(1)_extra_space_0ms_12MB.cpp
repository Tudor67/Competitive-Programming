class Solution {
public:
    void sortColors(vector<int>& nums) {
        const int N = nums.size();

        int p0 = -1;
        int p1 = -1;
        int p2 = N;

        int i = 0;
        while(i < p2){
            if(nums[i] == 0){
                p1 += 1;
                nums[p1] = 1;
                p0 += 1;
                nums[p0] = 0;
                i += 1;
            }else if(nums[i] == 1){
                p1 += 1;
                nums[p1] = 1;
                i += 1;
            }else{
                p2 -= 1;
                nums[i] = nums[p2];
                nums[p2] = 2;
            }
        }
    }
};