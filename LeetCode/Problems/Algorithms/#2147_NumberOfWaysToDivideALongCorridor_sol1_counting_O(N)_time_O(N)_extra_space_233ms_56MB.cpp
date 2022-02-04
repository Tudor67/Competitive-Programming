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
        vector<int> seatIndices;
        for(int i = 0; i < N; ++i){
            if(corridor[i] == 'S'){
                seatIndices.push_back(i);
            }
        }
        
        long long answer = 1;
        for(int i = 2; i < (int)seatIndices.size(); i += 2){
            answer = (answer * (seatIndices[i] - seatIndices[i - 1])) % MODULO;
        }
        
        return answer;
    }
};