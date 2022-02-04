class Solution {
public:
    int numberOfWays(string corridor) {
        const int N = corridor.length();
        const int SEATS_COUNT = count(corridor.begin(), corridor.end(), 'S');
        const int MODULO = 1e9 + 7;
        
        // Step 1: special cases
        if(SEATS_COUNT == 0 || SEATS_COUNT % 2 == 1){
            return 0;
        }
        
        // Step 2: standard counting
        long long answer = 1;
        int prevSeatIdx = -1;
        int seats = 0;
        for(int i = 0; i < N; ++i){
            if(corridor[i] == 'S'){
                seats += 1;
                if(seats % 2 == 1 && prevSeatIdx != -1){
                    answer = (answer * (i - prevSeatIdx)) % MODULO;
                }
                prevSeatIdx = i;
            }
        }
        
        return answer;
    }
};