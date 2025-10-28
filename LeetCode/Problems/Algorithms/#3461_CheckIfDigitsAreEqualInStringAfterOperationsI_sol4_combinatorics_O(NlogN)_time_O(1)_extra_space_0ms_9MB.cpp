class Solution {
public:
    bool hasSameDigits(string s) {
        const int N = s.length();

        vector<int> modInv = {0, 1, 0, 7, 0, 0, 0, 3, 0, 9};
        vector<int> pows2 = {2, 4, 8, 6};

        int exp2 = 0;
        int exp5 = 0;
        int x = 1;

        int lRem = 0;
        int rRem = 0;
        for(int i = 0; i < N - 1; ++i){
            if(exp2 == 0 || exp5 == 0){
                // binomCoef = nCk(N - 2, i) % 10 = (2 ^ exp2) * (5 ^ exp5) * x % 10
                int binomCoef = x;
                if(exp2 >= 1){
                    binomCoef = binomCoef * pows2[(exp2 - 1) % pows2.size()] % 10;
                }else if(exp5 >= 1){
                    binomCoef = binomCoef * 5 % 10;
                }
                lRem = (lRem + binomCoef * (s[i] - '0')) % 10;
                rRem = (rRem + binomCoef* (s[N - 1 - i] - '0')) % 10;
            }

            // prepare for the next step
            // nCk(N - 2, i + 1) % 10 = nCk(N - 2, i) * (N - 2 - i) / (i + 1) % 10
            int a = N - 2 - i;
            while(a > 0 && a % 2 == 0){
                exp2 += 1;
                a /= 2;
            }
            while(a > 0 && a % 5 == 0){
                exp5 += 1;
                a /= 5;
            }
            x = x * (a % 10) % 10;

            int b = i + 1;
            while(b > 0 && b % 2 == 0){
                exp2 -= 1;
                b /= 2;
            }
            while(b > 0 && b % 5 == 0){
                exp5 -= 1;
                b /= 5;
            }
            x = x * modInv[b % 10] % 10;
        }

        return (lRem == rRem);
    }
};