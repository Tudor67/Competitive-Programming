class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        const int N = arr.size();

        vector<int> suffMin(N + 1, INT_MAX);
        for(int i = N - 1; i >= 0; --i){
            suffMin[i] = min(arr[i], suffMin[i + 1]);
        }

        int maxChunks = 0;
        int prefMax = arr[0];
        for(int i = 0; i < N; ++i){
            prefMax = max(prefMax, arr[i]);
            if(prefMax <= suffMin[i + 1]){
                maxChunks += 1;
            }
        }

        return maxChunks;
    }
};