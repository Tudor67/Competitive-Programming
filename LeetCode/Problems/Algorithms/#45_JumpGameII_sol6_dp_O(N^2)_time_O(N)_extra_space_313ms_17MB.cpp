class Solution {
public:
    int jump(vector<int>& nums) {
        const int N = nums.size();
        const int INF = 1e9;

        // minJumps[x]: min jumps to reach position N - 1
        //              when we start from position x
        vector<int> minJumps(N, INF);
        minJumps[N - 1] = 0;
        for(int i = N - 2; i >= 0; --i){
            for(int j = min(N - 1, i + nums[i]); j >= i + 1; --j){
                minJumps[i] = min(minJumps[i], 1 + minJumps[j]);
            }
        }

        return minJumps[0];
    }
};