class Solution {
public:
    int minKBitFlips(vector<int>& A, int K) {
        const int N = A.size();
        int flipsCount = 0;
        
        bool flipStatus = false;
        vector<bool> flipUpdate(N + 1, false);
        for(int i = 0; i < N; ++i){
            flipStatus ^= flipUpdate[i];
            if(A[i] ^ flipStatus == 0){
                flipStatus ^= 1;
                flipsCount += 1;
                if(i + K >= N + 1){
                    flipsCount = -1;
                    break;
                }
                flipUpdate[i + K] = true;
            }
        }
        
        return flipsCount;
    }
};