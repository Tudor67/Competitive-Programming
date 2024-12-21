class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        const int N = arr.size();

        int maxChunks = 0;
        int visMask = 0;

        for(int i = 0; i < N; ++i){
            visMask |= (1 << arr[i]);
            int targetSubmask = (1 << (i + 1)) - 1;
            if((visMask & targetSubmask) == targetSubmask){
                maxChunks += 1;
            }
        }

        return maxChunks;
    }
};