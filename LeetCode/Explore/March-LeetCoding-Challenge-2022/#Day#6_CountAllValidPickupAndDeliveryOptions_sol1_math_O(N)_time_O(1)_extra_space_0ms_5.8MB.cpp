class Solution {
public:
    int countOrders(int n) {
        const int MODULO = 1e9 + 7;
        long long res = 1;
        for(int i = 1; i <= n; ++i){
            res *= ((2 * i - 1) * i) % MODULO;
            res %= MODULO;
        }
        return res;
    }
};

/*
n = 1
P1 D1

n = 2
_ _ P1 D1
_ P1 _ D1
_ P1 D1 _
P1 _ _ D1
P1 _ D1 _
P1 D1 _ _

n = 1 => res = 1
n = 2 => res *= nCk(2 * n, 2) => res = 1 * 6 => res = 6
n = 3 => res *= nCk(2 * n, 2) => res = 6 * 15 => res = 90

nCk(n, k) = n! / ((n - k)! * k!)
nCk(2 * n, 2) = (2 * n)! / (2 * (2 * n - 2)!) =
              = (2 * n - 1) * 2n / 2 =
              = (2 * n - 1) * n
              
res(n) = (1 * 1) * (3 * 2) * (5 * 3) * (7 * 4) * ... * ((2 * n - 1) * n) % MODULO
*/