class Solution {
public:
    int longestSubstring(string s, int k) {
        const int N = s.length();
        const int MIN_CHAR = 'a';
        const int MAX_CHAR = 'z';
        const int COUNT_SIZE = MAX_CHAR + 1;
        
        int answer = 0;
        vector<int> count(COUNT_SIZE);
        for(int maxUniqueCharsCount = 1; maxUniqueCharsCount <= 26; ++maxUniqueCharsCount){
            fill(count.begin() + MIN_CHAR, count.begin() + MAX_CHAR + 1, 0);
            int uniqueCharsCount = 0;
            int validCharsCount = 0;
            int totalCharsCount = 0;
            for(int i = 0, j = 0; j < N; ++j){
                count[s[j]] += 1;
                uniqueCharsCount += (count[s[j]] == 1);
                validCharsCount += (count[s[j]] == k);
                totalCharsCount += 1;
                while(uniqueCharsCount > maxUniqueCharsCount){
                    count[s[i]] -= 1;
                    uniqueCharsCount -= (count[s[i]] == 0);
                    validCharsCount -= (count[s[i]] == k - 1);
                    totalCharsCount -= 1;
                    i += 1;
                }
                if(uniqueCharsCount == validCharsCount){
                    answer = max(totalCharsCount, answer);
                }
            }
        }
        
        return answer;
    }
};