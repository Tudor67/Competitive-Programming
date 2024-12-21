class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        const int N = arr.size();
        const int FULL_MASK = (1 << N) - 1;

        int maxChunks = 1;
        vector<bool> vis(N);

        for(int mask = 1; mask <= FULL_MASK; ++mask){
            if(((mask >> (N - 1)) & 1) == 0){
                continue;
            }

            bool isValid = true;
            int prevBit = -1;
            fill(vis.begin(), vis.end(), false);

            for(int bit = 0; bit < N; ++bit){
                vis[arr[bit]] = true;
                if((mask >> bit) & 1){
                    if(count(vis.begin() + prevBit + 1, vis.begin() + bit + 1, true) != bit - prevBit){
                        isValid = false;
                        break;
                    }
                    prevBit = bit;
                }
            }

            if(isValid){
                maxChunks = max(maxChunks, __builtin_popcount(mask));
            }
        }

        return maxChunks;
    }
};