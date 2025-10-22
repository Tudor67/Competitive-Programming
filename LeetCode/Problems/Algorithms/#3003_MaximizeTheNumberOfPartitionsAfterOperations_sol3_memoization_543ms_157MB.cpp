class Solution {
private:
    int f(int changes, int i, unsigned int mask, string& s, int k, unordered_map<long long, int>& memo){
        if(i == (int)s.length()){
            return 1;
        }

        long long state = changes | (i << 1) | ((long long)mask << 15);
        if(memo.count(state)){
            return memo[state];
        }

        int res = 0;
        char firstCharCandidate = (changes == 0 ? 'a' : s[i]);
        char lastCharCandidate = (changes == 0 ? 'z' : s[i]);
        
        for(char c = firstCharCandidate; c <= lastCharCandidate; ++c){
            if(popcount(mask | (1 << (c - 'a'))) == k + 1){
                res = max(res, 1 + f(changes + (int)(c != s[i]), i + 1, 1 << (c - 'a'), s, k, memo));
            }else{
                res = max(res, f(changes + (int)(c != s[i]), i + 1, mask | (1 << (c - 'a')), s, k, memo));
            }
        }

        memo[state] = res;
        return res;
    }

public:
    int maxPartitionsAfterOperations(string s, int k) {
        unordered_map<long long, int> memo;
        return f(0, 0, 0, s, k, memo);
    }
};