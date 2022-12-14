class Solution {
public:
    int climbStairs(int n) {
        vector<int> ways(2);
        ways[0] = 1;
        ways[1] = 1;
        for(int i = 2; i <= n; ++i){
            ways[i % 2] = ways[(i - 1) % 2] + ways[(i - 2) % 2];
        }
        return ways[n % 2];
    }
};