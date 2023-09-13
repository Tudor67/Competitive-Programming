class Solution {
public:
    int countCompleteComponents(int N, vector<vector<int>>& edges) {
        vector<long long> nodeToEdgeMask(N);
        for(int node = 0; node < N; ++node){
            nodeToEdgeMask[node] |= (1LL << node);
        }
        
        for(const vector<int>& E: edges){
            int a = E[0];
            int b = E[1];
            nodeToEdgeMask[a] |= (1LL << b);
            nodeToEdgeMask[b] |= (1LL << a);
        }

        unordered_map<long long, int> count;
        for(int node = 0; node < N; ++node){
            count[nodeToEdgeMask[node]] += 1;
        }

        int completeCC = 0;
        for(const pair<long long, int>& P: count){
            long long edgeMask = P.first;
            if(__builtin_popcountll(edgeMask) == P.second){
                completeCC += 1;
            }
        }

        return completeCC;
    }
};