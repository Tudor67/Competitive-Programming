class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        const int N = nums.size();

        int visCount = 0;
        vector<bool> vis(k + 1, false);
        
        for(int i = N - 1; i >= 0; --i){
            if(nums[i] <= k && !vis[nums[i]]){
                visCount += 1;
                vis[nums[i]] = true;
            }
            if(visCount == k){
                return N - i;
            }
        }

        return -1;
    }
};