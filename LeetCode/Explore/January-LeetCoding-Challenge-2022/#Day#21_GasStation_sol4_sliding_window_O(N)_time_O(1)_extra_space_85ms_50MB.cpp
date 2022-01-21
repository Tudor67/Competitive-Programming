class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        const int N = gas.size();
        
        int currentGas = 0;
        int i = 0;
        for(int j = 0; j < 2 * N; ++j){
            currentGas += (gas[j % N] - cost[j % N]);
            while(currentGas < 0){
                currentGas -= (gas[i % N] - cost[i % N]);
                i += 1;
            }
            if(j - i + 1 == N && currentGas >= 0){
                return i;
            }
        }
        
        return -1;
    }
};