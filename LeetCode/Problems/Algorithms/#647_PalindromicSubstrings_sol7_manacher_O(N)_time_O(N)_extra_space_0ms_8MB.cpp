class Solution {
public:
    int countSubstrings(string inputStr) {
        const int N = 2 * inputStr.length() + 1;

        string s(N, '.');
        for(int i = 0; i < (int)inputStr.length(); ++i){
            s[2 * i + 1] = inputStr[i];
        }

        vector<int> r(N);
        int a = 0;
        int b = 0;
        for(int i = 0; i < N; ++i){
            if(i <= b){
                r[i] = min(b - i, r[a + (b - i)]);
            }
            while(0 <= i - r[i] - 1 && i + r[i] + 1 < N && s[i - r[i] - 1] == s[i + r[i] + 1]){
                r[i] += 1;
            }
            if(b < i + r[i]){
                a = i - r[i];
                b = i + r[i];
            }
        }

        int res = 0;
        for(int i = 0; i < N; ++i){
            res += (r[i] + 1) / 2;
        }

        return res;
    }
};