class Solution {
public:
    int minOperations(vector<int>& nums) {
        const int N = nums.size();
        const int INF = INT_MAX;
        
        int minOps = INF;
        int incNeighbors = 0;
        for(int i = 0; i < 2 * N - 1; ++i){
            if(i >= 1){
                incNeighbors += (int)(nums[(i - 1) % N] < nums[i % N]);
            }
            if(i >= N){
                incNeighbors -= (int)(nums[(i - N) % N] < nums[(i - N + 1) % N]);
            }

            if(i >= N - 1){
                int startIndex = i - N + 1;
                if(incNeighbors == N - 1){
                    minOps = min(minOps, startIndex);
                    minOps = min(minOps, N - startIndex + 2);
                }
                if(incNeighbors == 0){
                    minOps = min(minOps, startIndex + 1);
                    minOps = min(minOps, N - startIndex + 1);
                }
            }
        }

        if(minOps == INF){
            minOps = -1;
        }

        return minOps;
    }
};