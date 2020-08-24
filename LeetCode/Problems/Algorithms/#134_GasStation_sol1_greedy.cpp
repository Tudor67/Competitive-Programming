class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        const int N = gas.size();
        int s = 0;
        int start_idx = 0;
        for(int i = 0; i < 2 * N; ++i){
            s += gas[i % N] - cost[i % N];
            if(s < 0){
                s = 0;
                start_idx = i + 1;
            }else if(s >= 0 && i - start_idx + 1 == N){
                return start_idx;
            }
            
        }
        return -1;
    }
};