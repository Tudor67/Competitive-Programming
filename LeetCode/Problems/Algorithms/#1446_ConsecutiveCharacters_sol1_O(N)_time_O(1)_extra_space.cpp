class Solution {
public:
    int maxPower(string s) {
        int answer = 1;
        int cnt = 1;
        for(int i = 1; i < s.length(); ++i){
            if(s[i - 1] == s[i]){
                cnt += 1;
                answer = max(cnt, answer);
            }else{
                cnt = 1;
            }
        }
        return answer;
    }
};