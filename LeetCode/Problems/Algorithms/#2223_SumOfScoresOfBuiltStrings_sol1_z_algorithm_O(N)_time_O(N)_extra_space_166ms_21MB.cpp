class Solution {
public:
    long long sumScores(string s) {
        const int N = s.length();
        
        vector<int> z(N);
        int l = 0;
        int r = 0;
        for(int i = 1; i < N; ++i){
            if(i <= r){
                z[i] = min(z[i - l], r - i + 1);
            }
            while(i + z[i] < N && s[z[i]] == s[i + z[i]]){
                ++z[i];
            }
            if(i + z[i] - 1 >= r){
                l = i;
                r = i + z[i] - 1;
            }
        }
        
        long long res = N;
        for(int i = 1; i < N; ++i){
            res += z[i];
        }
        
        return res;
    }
};