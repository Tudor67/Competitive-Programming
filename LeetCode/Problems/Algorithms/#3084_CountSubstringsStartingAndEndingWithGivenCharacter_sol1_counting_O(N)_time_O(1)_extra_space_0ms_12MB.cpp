class Solution {
public:
    long long countSubstrings(string s, char c) {
        long long cFreq = 0;
        for(char currChar: s){
            if(currChar == c){
                cFreq += 1;
            }
        }
        return cFreq * (cFreq + 1) / 2;
    }
};