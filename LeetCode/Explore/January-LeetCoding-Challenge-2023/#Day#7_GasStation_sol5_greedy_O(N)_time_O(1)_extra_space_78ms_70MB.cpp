class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        const int N = gas.size();

        int startPos = 0;
        int currentGas = gas[0];
        for(int pos = 1; pos < 2 * N; ++pos){
            currentGas -= cost[(pos - 1) % N];
            if(currentGas < 0){
                startPos = pos;
                currentGas = gas[pos % N];
            }else{
                currentGas += gas[pos % N];
                if(pos - startPos + 1 == N + 1){
                    return startPos;
                }
            }
        }

        return -1;
    }
};