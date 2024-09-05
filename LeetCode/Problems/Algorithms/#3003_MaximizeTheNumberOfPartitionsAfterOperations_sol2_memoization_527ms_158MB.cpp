class Solution {
private:
    int computeMaxPartitions(int i, int mask, bool canChange, string& s, int k, unordered_map<long long, int>& memo){
        const int N = s.length();

        if(i == N){
            return 1;
        }

        long long state = i | ((long long)canChange << 15) | ((long long)mask << 16);
        if(memo.count(state)){
            return memo[state];
        }

        int res = 0;
        int mask0 = mask | (1 << (s[i] - 'a'));
        if(popcount((unsigned int)mask0) > k){
            mask0 = (1 << (s[i] - 'a'));
            res = max(res, 1 + computeMaxPartitions(i + 1, mask0, canChange, s, k, memo));
        }else{
            res = max(res, computeMaxPartitions(i + 1, mask0, canChange, s, k, memo));
        }

        for(char c = 'a'; c <= 'z' && canChange; ++c){
            if(!((mask >> (c - 'a')) & 1)){
                int mask1 = mask | (1 << (c - 'a'));
                if(popcount((unsigned int)mask1) > k){
                    mask1 = (1 << (c - 'a'));
                    res = max(res, 1 + computeMaxPartitions(i + 1, mask1, false, s, k, memo));
                }else{
                    res = max(res, computeMaxPartitions(i + 1, mask1, false, s, k, memo));
                }
            }
        }

        memo[state] = res;
        return res;
    }

public:
    int maxPartitionsAfterOperations(string s, int k) {
        unordered_map<long long, int> memo;
        return computeMaxPartitions(0, 0, true, s, k, memo);
    }
};