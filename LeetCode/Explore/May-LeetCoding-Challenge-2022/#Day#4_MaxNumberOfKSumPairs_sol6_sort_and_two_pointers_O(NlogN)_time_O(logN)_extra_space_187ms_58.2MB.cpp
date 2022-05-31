class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        const int N = nums.size();
        
        sort(nums.begin(), nums.end());
        
        int res = 0;
        int i = 0;
        int j = N - 1;
        while(i < j){
            if(nums[i] + nums[j] < k){
                i += 1;
            }else if(nums[i] + nums[j] > k){
                j -= 1;
            }else{
                res += 1;
                i += 1;
                j -= 1;
            }
        }
        
        return res;
    }
};