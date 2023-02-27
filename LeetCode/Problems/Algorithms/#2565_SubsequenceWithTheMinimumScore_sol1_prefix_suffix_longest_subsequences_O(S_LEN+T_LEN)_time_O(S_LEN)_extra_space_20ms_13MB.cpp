class Solution {
public:
    int minimumScore(string s, string t) {
        const int S_LEN = s.length();
        const int T_LEN = t.length();
        
        // prefixMatch[i]: size of the longest prefix of t that is a subsequence of prefix s[0 .. i]
        vector<int> prefixMatch(S_LEN);
        int j = 0;
        for(int i = 0; i < S_LEN; ++i){
            if(j < T_LEN && s[i] == t[j]){
                j += 1;
            }
            prefixMatch[i] = j;
        }
        
        // suffixMatch[i]: size of the longest suffix of t that is a subsequence of suffix s[i .. S_LEN - 1]
        vector<int> suffixMatch(S_LEN + 1);
        j = T_LEN - 1;
        for(int i = S_LEN - 1; i >= 0; --i){
            if(j >= 0 && s[i] == t[j]){
                j -= 1;
            }
            suffixMatch[i] = T_LEN - 1 - j;
        }
        
        // for all indices i:
        //     fix index i and compute the cost of making t a subsequence of s;
        //
        //     prefix t[0 .. prefixMatch[i] - 1] is the longest prefix of t that is a subsequence
        //     of prefix s[0 .. i];
        //     suffix t[T_LEN - suffixMatch[i + 1] .. T_LEN - 1] is the longest suffix of t that is a subsequence
        //     of suffix s[i + 1 .. S_LEN - 1];
        //
        //     the min/first unmatching char is at index prefixMatch[i];
        //     the max/last unmatching char is at index T_LEN - suffixMatch[i + 1] - 1;
        //
        //     the current cost = max(0, T_LEN - suffixMatch[i + 1] - prefixMatch[i]);
        //     the current cost represents the length of the
        //     unmatching substring t[prefixMatch[i] .. T_LEN - suffixMatch[i + 1] - 1];
        //
        //     update the final result res = min(res, cost);
        int res = T_LEN - suffixMatch[0];
        for(int i = 0; i < S_LEN; ++i){
            int matches = prefixMatch[i] + suffixMatch[i + 1];
            int cost = max(0, T_LEN - matches);
            res = min(res, cost);
        }
        
        return res;
    }
};