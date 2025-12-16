class Solution {
public:
    int numberOfWays(string corridor) {
        const int N = corridor.length();
        const int TOTAL_SEATS = count(corridor.begin(), corridor.end(), 'S');
        const int MODULO = 1'000'000'007;

        if(TOTAL_SEATS == 0 || TOTAL_SEATS % 2 == 1){
            return 0;
        }

        vector<int> freq(TOTAL_SEATS + 1);
        int seatsPrefCount = 0;
        for(char c: corridor){
            seatsPrefCount += (int)(c == 'S');
            freq[seatsPrefCount] += 1;
        }

        long long res = 1;
        for(int s = 2; s <= TOTAL_SEATS - 2; s += 2){
            res = (res * freq[s]) % MODULO;
        }

        return res;
    }
};