class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        const int N = gas.size();
        
        int currentGas = 0;
        int startIdx = 0;
        for(int i = 0; i < 2 * N; ++i){
            currentGas += (gas[i % N] - cost[i % N]);
            if(currentGas < 0){
                currentGas = 0;
                startIdx = i + 1;
            }
            if(i - startIdx + 1 == N){
                return startIdx;
            }
        }
        
        return -1;
    }
};