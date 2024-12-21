class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        const int N = arr.size();

        int maxChunks = 0;
        vector<bool> vis(N, false);

        for(int i = 0; i < N; ++i){
            vis[arr[i]] = true;
            if(count(vis.begin(), vis.begin() + i + 1, true) == i + 1){
                maxChunks += 1;
            }
        }

        return maxChunks;
    }
};