class Solution {
public:
    int countSubstrings(string s) {
        const int N = s.length();
        
        string ss(2 * N + 1, '.');
        for(int i = 0; i < N; ++i){
            ss[2 * i + 1] = s[i];
        }
        
        int res = 0;
        vector<int> r(2 * N + 1, 1);
        int x = 0;
        int y = 0;
        for(int i = 0; i < 2 * N + 1; ++i){
            if(i <= y){
                r[i] = min(r[x + y - i], y - i + 1);
            }
            while(0 <= i - r[i] && i + r[i] < 2 * N + 1 && ss[i - r[i]] == ss[i + r[i]]){
                r[i] += 1;
            }
            res += r[i] / 2;
            if(i + r[i] - 1 > y){
                x = i - r[i] + 1;
                y = i + r[i] - 1;
            }
        }
        
        return res;
    }
};