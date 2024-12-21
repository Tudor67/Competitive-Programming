class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        const int N = arr.size();

        int maxChunks = 0;
        int prefixMax = 0;
        for(int i = 0; i < N; ++i){
            prefixMax = max(prefixMax, arr[i]);
            if(prefixMax == i){
                maxChunks += 1;
            }
        }

        return maxChunks;
    }
};