class Solution {
private:
    long long countSubsequences(string text, string pattern){
        long long count0 = 0;
        long long totalCount = 0;
        for(char c: text){
            if(c == pattern[1]){
                totalCount += count0;
            }
            if(c == pattern[0]){
                count0 += 1;
            }
        }
        return totalCount;
    }
    
public:
    long long maximumSubsequenceCount(string text, string pattern) {
        return max(countSubsequences(string(1, pattern[0]) + text, pattern),
                   countSubsequences(text + string(1, pattern[1]), pattern));
    }
};