class Solution {
public:
    int jump(vector<int>& nums) {
        const int N = nums.size();
        
        vector<int> prefMax(N, 0);
        prefMax[0] = nums[0];
        for(int idx = 1; idx < N; ++idx){
            prefMax[idx] = max(prefMax[idx - 1], idx + nums[idx]);
        }
        
        int idx = 0;
        int minJumps = 0;
        while(idx < N - 1){
            idx = prefMax[idx];
            minJumps += 1;
        }
        
        return minJumps;
    }
};