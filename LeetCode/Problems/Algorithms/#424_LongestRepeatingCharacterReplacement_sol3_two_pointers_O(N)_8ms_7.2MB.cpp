class Solution {
public:
    int characterReplacement(string s, int k) {
        int answer = 0;
        int maxCntPos = 0;
        vector<int> cnt(128, 0);
        for(int i = 0, j = 0; j < s.length(); ++j){
            cnt[s[j]] += 1;
            if(cnt[s[j]] >= cnt[s[maxCntPos]]){
                maxCntPos = j;
            }
            while(j - i + 1 - cnt[s[maxCntPos]] > k){
                cnt[s[i]] -= 1;
                i += 1;
            }
            answer = max(j - i + 1, answer);
        }
        return answer;
    }
};