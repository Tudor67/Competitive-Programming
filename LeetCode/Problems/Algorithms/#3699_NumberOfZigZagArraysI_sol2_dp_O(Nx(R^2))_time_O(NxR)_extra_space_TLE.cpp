class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        const int MODULO = 1'000'000'007;

        vector<vector<int>> dec(n + 1, vector<int>(r + 1));
        vector<vector<int>> inc(n + 1, vector<int>(r + 1));

        for(int a = l; a <= r; ++a){
            for(int b = l; b <= r; ++b){
                if(a > b){
                    dec[2][b] += 1;
                    dec[2][b] %= MODULO;
                }else if(a < b){
                    inc[2][b] += 1;
                    inc[2][b] %= MODULO;
                }
            }
        }

        for(int len = 3; len <= n; ++len){
            for(int b = l; b <= r; ++b){
                for(int a = l; a <= r; ++a){
                    if(a > b){
                        dec[len][b] += inc[len - 1][a];
                        dec[len][b] %= MODULO;
                    }else if(a < b){
                        inc[len][b] += dec[len - 1][a];
                        inc[len][b] %= MODULO;
                    }
                }
            }
        }

        int res = 0;
        for(int a = l; a <= r; ++a){
            res += dec[n][a];
            res %= MODULO;
            res += inc[n][a];
            res %= MODULO;
        }

        return res;
    }
};