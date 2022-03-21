class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        const int N = nums.size();
        
        int res = 0;
        int i = 1;
        while(i < N){
            int j = i;
            while(j + 1 < N && nums[i] - nums[i - 1] == nums[j + 1] - nums[j]){
                j += 1;
            }
            int k = j - i;
            res += (k * (k + 1)) / 2;
            i = j + 1;
        }
        
        return res;
    }
};