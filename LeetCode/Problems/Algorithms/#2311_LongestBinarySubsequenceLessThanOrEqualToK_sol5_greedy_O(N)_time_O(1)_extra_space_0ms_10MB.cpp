class Solution {
public:
    int longestSubsequence(string s, int k) {
        const int N = s.length();

        int prefZeros = count(s.begin(), s.end(), '0');
        int maxLen = prefZeros;
        int pow2 = 1;
        int suffNum = 0;

        for(int i = N - 1; i >= 0 && pow2 <= k; --i){
            if(s[i] == '0'){
                prefZeros -= 1;
            }else if(pow2 + suffNum <= k){
                suffNum += pow2;
                maxLen = max(maxLen, prefZeros + N - i);
            }else{
                break;
            }
            pow2 *= 2;
        }

        return maxLen;
    }
};