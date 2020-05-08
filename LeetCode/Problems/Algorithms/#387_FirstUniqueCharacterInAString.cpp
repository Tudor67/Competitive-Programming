class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> cnt(26, 0);
        for(char c: s){
            ++cnt[c - 'a'];
        }
        
        int answer = -1;
        for(int i = 0; i < s.length(); ++i){
            if(cnt[s[i] - 'a'] == 1){
                answer = i;
                break;
            }
        }
        
        return answer;
    }
};