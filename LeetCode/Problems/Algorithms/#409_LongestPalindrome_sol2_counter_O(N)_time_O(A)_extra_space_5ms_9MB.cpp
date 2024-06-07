class Solution {
public:
    int longestPalindrome(string s) {
        const int N = s.length();

        unordered_map<char, int> freq;
        for(char c: s){
            freq[c] += 1;
        }

        int maxLen = 0;
        bool containsOddFreq = false;
        for(const pair<const char, int>& P: freq){
            int charFreq = P.second;
            if(charFreq % 2 == 0){
                maxLen += charFreq;
            }else{
                maxLen += charFreq - 1;
                containsOddFreq = true;
            }
        }

        return maxLen + (int)containsOddFreq;
    }
};