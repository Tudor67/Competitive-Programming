class Solution {
public:
    int countSubstrings(string s) {
        const int N = s.length();
        int answer = N;
        for(bool isOfEvenLength: {false, true}){
            for(int i = 0; i < N; ++i){
                int k = 1;
                while(0 <= i - k + isOfEvenLength && i + k < N && s[i - k + isOfEvenLength] == s[i + k]){
                    k += 1;
                }
                answer += k - 1;
            }
        }
        return answer;
    }
};