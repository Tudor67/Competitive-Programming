class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        const int N = arr.size();

        int maxChunks = 0;
        vector<bool> vis(N, false);

        int maxVisPrefixVal = -1;
        for(int i = 0; i < N; ++i){
            vis[arr[i]] = true;
            while(maxVisPrefixVal + 1 < N && vis[maxVisPrefixVal + 1]){
                maxVisPrefixVal += 1;
            }
            if(maxVisPrefixVal == i){
                maxChunks += 1;
            }
        }

        return maxChunks;
    }
};