class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        const int N = nums.size();
        
        long long res = 0;
        int suffMin = nums[N - 1];
        for(int i = N - 2; i >= 0; --i){
            if(nums[i] <= suffMin){
                suffMin = nums[i];
            }else{
                int x = (nums[i] + suffMin - 1) / suffMin;
                res += (x - 1);
                suffMin = nums[i] / x;
            }
        }
        
        return res;
    }
};