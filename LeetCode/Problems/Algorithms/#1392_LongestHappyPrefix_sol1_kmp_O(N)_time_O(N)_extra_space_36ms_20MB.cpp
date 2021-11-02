class Solution {
public:
    string longestPrefix(string s) {
        const int N = s.length();
        vector<int> p(N);
        for(int i = 1; i < N; ++i){
            int k = p[i - 1];
            while(k > 0 && s[k] != s[i]){
                k = p[k - 1];
            }
            if(s[k] == s[i]){
                p[i] = k + 1;
            }
        }
        return s.substr(0, p[N - 1]);
    }
};