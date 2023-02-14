class Solution {
public:
    int jump(vector<int>& nums) {
        const int N = nums.size();

        int totalJumps = 0;
        int l = 0;
        int r = 0;

        while(r < N - 1){
            totalJumps += 1;
            int maxReachablePos = r;
            for(int i = l; i <= r; ++i){
                maxReachablePos = max(maxReachablePos, i + nums[i]);
            }
            l = r + 1;
            r = maxReachablePos;
        }

        return totalJumps;
    }
};