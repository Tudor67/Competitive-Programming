class Solution {
public:
    int jump(vector<int>& nums) {
        const int N = nums.size();
        const int INF = 1e8;
        
        // minJumps[`i`]: min number of jumps to reach the last index if we start from index `i`
        vector<int> minJumps(N, INF);
        minJumps[N - 1] = 0;
        for(int i = N - 2; i >= 0; --i){
            for(int j = i + 1; j <= min(N - 1, i + nums[i]); ++j){
                minJumps[i] = min(1 + minJumps[j], minJumps[i]);
            }
        }
        
        return minJumps[0];
    }
};