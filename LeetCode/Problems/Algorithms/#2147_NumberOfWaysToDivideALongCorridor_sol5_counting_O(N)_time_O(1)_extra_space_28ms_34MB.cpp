class Solution {
public:
    int numberOfWays(string corridor) {
        const int N = corridor.length();
        const int TOTAL_SEATS = count(corridor.begin(), corridor.end(), 'S');
        const int MODULO = 1'000'000'007;

        if(TOTAL_SEATS == 0 || TOTAL_SEATS % 2 == 1){
            return 0;
        }

        long long res = 1;
        int seatsPrefCount = 0;
        int plantsSuffCount = 0;

        for(int i = 0; i < N; ++i){
            if(corridor[i] == 'S'){
                seatsPrefCount += 1;
                plantsSuffCount = 0;
            }else{
                plantsSuffCount += 1;
                if(i + 1 < N && corridor[i + 1] == 'S' && seatsPrefCount >= 2 && seatsPrefCount % 2 == 0){
                    res = res * (plantsSuffCount + 1) % MODULO;
                }
            }
        }

        return res;
    }
};