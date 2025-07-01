class Solution {
public:
    int longestSubsequence(string s, int k) {
        const int N = s.length();
        const int INF = 1e9;

        int res = 0;
        vector<int> currDP(N + 1, INF);
        vector<int> newDP(N + 1, INF);
        currDP[0] = 0;

        for(char c: s){
            copy(currDP.begin(), currDP.end(), newDP.begin());
            for(int seqLen = 0; seqLen <= N; ++seqLen){
                int num = currDP[seqLen];
                int newNum = num * 2 + (c - '0');
                int newSeqLen = seqLen + 1;
                if(newNum <= k){
                    newDP[newSeqLen] = min(newDP[newSeqLen], newNum);
                    res = max(res, newSeqLen);
                }
            }
            currDP.swap(newDP);
        }

        return res;
    }
};