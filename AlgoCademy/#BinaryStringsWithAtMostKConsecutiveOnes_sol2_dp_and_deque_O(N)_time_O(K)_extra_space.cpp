class Solution {
public:
    int countBinaryStrings(int n, int k) {
        deque<int> dp;
        int kSum = 0;
        for(int i = 0; i <= k; ++i){
            dp.push_back(1 << i);
            kSum += dp.back();
        }
        for(int i = k + 1; i <= n; ++i){
            dp.push_back(kSum);
            kSum -= dp.front();
            kSum += dp.back();
            dp.pop_front();
        }
        return dp.back();
    }
};