class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        const int N = s.length();

        int a = 0;
        int b = 0;
        vector<int> z(N);
        for(int i = 1; i < N; ++i){
            if(i <= b){
                z[i] = min(z[i - a], b - i + 1);
            }
            while(i + z[i] < N && s[z[i]] == s[i + z[i]]){
                z[i] += 1;
            }
            if(b < i + z[i] - 1){
                a = i;
                b = i + z[i] - 1;
            }

            if(i + z[i] == N && N % i == 0){
                return true;
            }
        }
        
        return false;
    }
};