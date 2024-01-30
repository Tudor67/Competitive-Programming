class Solution {
public:
    long long maxArrayValue(vector<int>& nums) {
        const int N = nums.size();
        
        long long res = 0;
        long long lastNum = 0;
        for(int i = N - 1; i >= 0; --i){
            if(nums[i] <= lastNum){
                lastNum += nums[i];
            }else{
                lastNum = nums[i];
            }
            res = max(res, lastNum);
        }
        
        return res;
    }
};