class Solution {
public:
    int numberOfSubstrings(string s) {
        const int N = s.length();
        
        int answer = 0;
        unordered_map<char, int> count;
        int uniqueChars = 0;
        int i = 0;
        for(int j = 0; j < N; ++j){
            count[s[j]] += 1;
            uniqueChars += (int)(count[s[j]] == 1);
            while(uniqueChars == 3){
                uniqueChars -= (int)(count[s[i]] == 1);
                count[s[i]] -= 1;
                i += 1;
            }
            answer += i;
        }
        
        return answer;
    }
};