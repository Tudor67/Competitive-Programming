class Solution {
public:
    int countCompleteComponents(int N, vector<vector<int>>& edges) {
        vector<long long> maskFor(N);
        for(int node = 0; node < N; ++node){
            maskFor[node] |= (1LL << node);
        }

        for(vector<int>& edge: edges){
            int a = edge[0];
            int b = edge[1];
            maskFor[a] |= (1LL << b);
            maskFor[b] |= (1LL << a);
        }

        unordered_map<long long, int> freqOf;
        for(int node = 0; node < N; ++node){
            freqOf[maskFor[node]] += 1;
        }

        int completeConnectedComponents = 0;
        for(auto& [mask, maskFreq]: freqOf){
            if(__builtin_popcountll(mask) == maskFreq){
                completeConnectedComponents += 1;
            }
        }

        return completeConnectedComponents;
    }
};