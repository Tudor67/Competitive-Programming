class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        const int N = gas.size();
        int answer = -1;
        
        int currentGas = 0;
        int startPos = 0;
        for(int i = 0; i < 2 * N; ++i){
            currentGas += gas[i % N] - cost[i % N];
            if(currentGas < 0){
                currentGas = 0;
                startPos = i + 1;
            }
            if(i - startPos + 1 == N){
                answer = startPos;
                break;
            }
        }
        
        return answer;
    }
};