class Solution {
public:
    int maximumLength(string s) {
        const int N = s.length();

        map<pair<char, int>, int> freq;
        int i = 0;
        while(i < N){
            int j = i;
            while(j < N && s[i] == s[j]){
                j += 1;
            }
            int len = j - i;
            freq[{s[i], len}] += 1;
            freq[{s[i], len - 1}] += 2;
            freq[{s[i], len - 2}] += 3;
            i = j;
        }

        int maxLen = -1;
        for(const pair<const pair<char, int>, int>& P: freq){
            int len = P.first.second;
            int lenFreq = P.second;
            if(len >= 1 && lenFreq >= 3){
                maxLen = max(maxLen, len);
            }
        }

        return maxLen;
    }
};