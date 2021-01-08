class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int answer = 0;
        bitset<128> visited;
        for(int i = 0, j = 0; j < s.length(); ++j){
            while(visited[s[j]]){
                visited[s[i]] = false;
                i += 1;
            }
            visited[s[j]] = true;
            answer = max(j - i + 1, answer);
        }
        return answer;
    }
};