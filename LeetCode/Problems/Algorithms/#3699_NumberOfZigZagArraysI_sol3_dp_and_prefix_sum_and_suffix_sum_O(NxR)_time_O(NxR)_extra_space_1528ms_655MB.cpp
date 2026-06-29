class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        const int MODULO = 1'000'000'007;

        // dec[len][a]: the number of valid zig zag arrays of length len
        //              whose last two elements are strictly decreasing,
        //              and whose last element <= a
        // inc[len][a]: the number of valid zig zag arrays of length len
        //              whose last two elements are strictly increasing,
        //              and whose last element >= a
        vector<vector<int>> dec(n + 1, vector<int>(r + 1));
        vector<vector<int>> inc(n + 1, vector<int>(r + 1));

        for(int a = l; a <= r; ++a){
            dec[2][a] = (r - a) % MODULO;
            inc[2][a] = (a - l) % MODULO;
        }

        for(int a = l + 1; a <= r; ++a){
            dec[2][a] += dec[2][a - 1];
            dec[2][a] %= MODULO;
        }

        for(int a = r - 1; a >= l; --a){
            inc[2][a] += inc[2][a + 1];
            inc[2][a] %= MODULO;
        }

        for(int len = 3; len <= n; ++len){
            for(int a = l; a <= r; ++a){
                if(a + 1 <= r){
                    dec[len][a] += inc[len - 1][a + 1];
                    dec[len][a] %= MODULO;
                }
                if(a - 1 >= l){
                    inc[len][a] += dec[len - 1][a - 1];
                    inc[len][a] %= MODULO;
                }
            }

            for(int a = l + 1; a <= r; ++a){
                dec[len][a] += dec[len][a - 1];
                dec[len][a] %= MODULO;
            }

            for(int a = r - 1; a >= l; --a){
                inc[len][a] += inc[len][a + 1];
                inc[len][a] %= MODULO;
            }
        }

        return (dec[n][r] + inc[n][l]) % MODULO;
    }
};