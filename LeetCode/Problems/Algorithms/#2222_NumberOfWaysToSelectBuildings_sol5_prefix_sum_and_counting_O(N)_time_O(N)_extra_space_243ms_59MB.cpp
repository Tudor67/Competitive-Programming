class Solution {
public:
    long long numberOfWays(string s) {
        const int N = s.length();
        
        vector<int> prefSum0(N);
        vector<int> prefSum1(N);
        prefSum0[0] = (int)(s[0] == '0');
        prefSum1[0] = (int)(s[0] == '1');
        for(int i = 1; i < N; ++i){
            prefSum0[i] = prefSum0[i - 1];
            prefSum1[i] = prefSum1[i - 1];
            if(s[i] == '0'){
                prefSum0[i] += 1;
            }else{
                prefSum1[i] += 1;
            }
        }
        
        long long res = 0;
        for(int i = 1; i + 1 < N; ++i){
            long long l = 0;
            long long r = 0;
            if(s[i] == '0'){
                l = prefSum1[i - 1];
                r = prefSum1[N - 1] - prefSum1[i];
            }else{
                l = prefSum0[i - 1];
                r = prefSum0[N - 1] - prefSum0[i];
            }
            res += (l * r);
        }
        
        return res;
    }
};