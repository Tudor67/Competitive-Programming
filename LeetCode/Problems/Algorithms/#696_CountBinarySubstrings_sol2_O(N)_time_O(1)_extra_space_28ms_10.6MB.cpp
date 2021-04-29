class Solution {
public:
    int countBinarySubstrings(string s) {
        const int N = s.length();
        int answer = 0;
        vector<int> count(2, 0);
        for(int i = 0; i < N; ++i){
            if(i > 0 && s[i - 1] != s[i]){
                answer += min(count[0], count[1]);
                count[s[i] - '0'] = 1;
            }else{
                count[s[i] - '0'] += 1;
            }
        }
        answer += min(count[0], count[1]);
        return answer;
    }
};