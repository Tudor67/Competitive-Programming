class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        const int MODULO = 1'000'000'007;

        // At (len)th iteration:
        // dec[len % 2][a]: the number of valid zig zag arrays of length len
        //                  whose last two elements are strictly decreasing,
        //                  and whose last element <= a
        // inc[len % 2][a]: the number of valid zig zag arrays of length len
        //                  whose last two elements are strictly increasing,
        //                  and whose last element >= a
        vector<vector<int>> dec(2, vector<int>(r + 1));
        vector<vector<int>> inc(2, vector<int>(r + 1));

        for(int a = l; a <= r; ++a){
            dec[0][a] = (r - a) % MODULO;
            inc[0][a] = (a - l) % MODULO;
        }

        for(int a = l + 1; a <= r; ++a){
            dec[0][a] += dec[0][a - 1];
            dec[0][a] %= MODULO;
        }

        for(int a = r - 1; a >= l; --a){
            inc[0][a] += inc[0][a + 1];
            inc[0][a] %= MODULO;
        }

        for(int len = 3; len <= n; ++len){
            fill(dec[len % 2].begin(), dec[len % 2].end(), 0);
            fill(inc[len % 2].begin(), inc[len % 2].end(), 0);
            for(int a = l; a <= r; ++a){
                if(a + 1 <= r){
                    dec[len % 2][a] += inc[(len - 1) % 2][a + 1];
                    dec[len % 2][a] %= MODULO;
                }
                if(a - 1 >= l){
                    inc[len % 2][a] += dec[(len - 1) % 2][a - 1];
                    inc[len % 2][a] %= MODULO;
                }
            }

            for(int a = l + 1; a <= r; ++a){
                dec[len % 2][a] += dec[len % 2][a - 1];
                dec[len % 2][a] %= MODULO;
            }

            for(int a = r - 1; a >= l; --a){
                inc[len % 2][a] += inc[len % 2][a + 1];
                inc[len % 2][a] %= MODULO;
            }
        }

        return (dec[n % 2][r] + inc[n % 2][l]) % MODULO;
    }
};