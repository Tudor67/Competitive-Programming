class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        const int N = arr.size();

        int maxChunks = 0;
        int prefixSum = 0;
        for(int i = 0; i < N; ++i){
            prefixSum += arr[i];
            if(prefixSum == i * (i + 1) / 2){
                maxChunks += 1;
            }
        }

        return maxChunks;
    }
};