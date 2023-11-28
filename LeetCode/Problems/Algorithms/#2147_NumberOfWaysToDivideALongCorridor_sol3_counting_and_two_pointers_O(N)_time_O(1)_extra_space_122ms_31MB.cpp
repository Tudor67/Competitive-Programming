class Solution {
public:
    int numberOfWays(string s) {
        const int N = s.length();
        const int MODULO = 1e9 + 7;
        const int TOTAL_SEATS = count(s.begin(), s.end(), 'S');

        if(TOTAL_SEATS == 0 || TOTAL_SEATS % 2 == 1){
            return 0;
        }

        long long res = 1;
        
        int i = 0;
        while(i < N){
            int j = i;
            int seats = 0;
            while(j < N && seats < 2){
                seats += (int)(s[j] == 'S');
                j += 1;
            }

            int plants = 0;
            while(j < N && s[j] == 'P'){
                plants += 1;
                j += 1;
            }
            if(j < N){
                res = (res * (plants + 1)) % MODULO;
            }

            i = j;
        }

        return res;
    }
};