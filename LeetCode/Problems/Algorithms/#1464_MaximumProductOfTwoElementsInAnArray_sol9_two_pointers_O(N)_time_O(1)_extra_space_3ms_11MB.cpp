class Solution {
public:
    int maxProduct(vector<int>& nums) {
        const int N = nums.size();

        int res = 0;

        int i = 0;
        int j = N - 1;
        while(i < j){
            res = max(res, (nums[i] - 1) * (nums[j] - 1));
            if(nums[i] < nums[j]){
                i += 1;
            }else{
                j -= 1;
            }
        }

        return res;
    }
};