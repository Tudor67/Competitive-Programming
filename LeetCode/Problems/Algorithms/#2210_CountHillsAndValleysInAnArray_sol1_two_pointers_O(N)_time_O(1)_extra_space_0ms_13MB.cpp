class Solution {
public:
    int countHillValley(vector<int>& nums) {
        const int N = nums.size();

        int res = 0;
        int l = 0;
        while(l < N){
            int r = l;
            while(r + 1 < N && nums[l] == nums[r + 1]){
                r += 1;
            }
            if(l - 1 >= 0 && r + 1 < N){
                if(max(nums[l - 1], nums[r + 1]) < nums[l] ||
                   min(nums[l - 1], nums[r + 1]) > nums[r]){
                    res += 1;
                }
            }
            l = r + 1;
        }

        return res;
    }
};