class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int answer = 0;
        vector<int> count(128, 0);
        for(int i = 0, j = 0; j < s.length(); ++j){
            count[s[j]] += 1;
            while(count[s[j]] == 2){
                count[s[i]] -= 1;
                i += 1;
            }
            answer = max(j - i + 1, answer);
        }
        return answer;
    }
};