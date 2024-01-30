class Solution {
private:
    void dfs(int node, int prefParityMask, unordered_map<int, int>& freq,
             const vector<vector<pair<int, char>>>& G, long long& res){
        for(const pair<int, char>& P: G[node]){
            int child = P.first;
            int colorIndex = P.second - 'a';
            int childPrefParityMask = prefParityMask ^ (1 << colorIndex);

            if(freq.count(childPrefParityMask)){
                res += freq[childPrefParityMask];
            }

            for(char c = 'a'; c <= 'z'; ++c){
                int targetMask = (1 << (c - 'a'));
                if(freq.count(childPrefParityMask ^ targetMask)){
                    res += freq[childPrefParityMask ^ targetMask];
                }
            }

            freq[childPrefParityMask] += 1;
            dfs(child, childPrefParityMask, freq, G, res);
        }
    }

public:
    long long countPalindromePaths(vector<int>& parent, string s) {
        const int N = parent.size();

        vector<vector<pair<int, char>>> G(N);
        for(int node = 1; node < N; ++node){
            G[parent[node]].push_back({node, s[node]});
        }

        unordered_map<int, int> freq = {{0, 1}};
        long long res = 0;
        dfs(0, 0, freq, G, res);

        return res;
    }
};