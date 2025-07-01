class Solution {
public:
    int longestSubsequence(string s, int k) {
        int res = 0;
        unordered_map<int, int> currDP;
        unordered_map<int, int> newDP;
        currDP[0] = 0;

        for(char c: s){
            newDP = currDP;
            for(auto [seqLen, num]: currDP){
                int newNum = num * 2 + (c - '0');
                int newSeqLen = seqLen + 1;
                if(newNum <= k){
                    if(newDP.count(newSeqLen)){
                        newDP[newSeqLen] = min(newDP[newSeqLen], newNum);
                    }else{
                        newDP[newSeqLen] = newNum;
                    }
                    res = max(res, newSeqLen);
                }
            }
            currDP.swap(newDP);
        }

        return res;
    }
};