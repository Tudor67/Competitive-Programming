class Solution {
private:
    using Graph = vector<vector<int>>;

    void dfs(int node, int cc, vector<int>& ccOf, vector<bool>& isPrime, const Graph& G){
        if(ccOf[node] != 0 || isPrime[node]){
            return;
        }
        ccOf[node] = cc;
        for(int nextNode: G[node]){
            dfs(nextNode, cc, ccOf, isPrime, G);
        }
    }

public:
    long long countPaths(int N, vector<vector<int>>& edges) {
        vector<bool> isPrime(N + 1, true);
        isPrime[0] = false;
        isPrime[1] = false;
        for(int i = 2; i <= N; ++i){
            if(isPrime[i]){
                for(int j = i + i; j <= N; j += i){
                    isPrime[j] = false;
                }
            }
        }

        Graph G(N + 1);
        for(const vector<int>& EDGE: edges){
            int a = EDGE[0];
            int b = EDGE[1];
            G[a].push_back(b);
            G[b].push_back(a);
        }

        int cc = 0;
        vector<int> ccOf(N + 1);
        for(int node = 1; node <= N; ++node){
            if(!isPrime[node] && ccOf[node] == 0){
                cc += 1;
                dfs(node, cc, ccOf, isPrime, G);
            }
        }

        vector<int> ccSizeOf(cc + 1);
        for(int node = 1; node <= N; ++node){
            ccSizeOf[ccOf[node]] += 1;
        }

        long long res = 0;
        for(int a = 1; a <= N; ++a){
            long long nonPrimesCount = 0;
            for(int b: G[a]){
                if(isPrime[a] && !isPrime[b]){
                    long long c = ccSizeOf[ccOf[b]];
                    res += c * nonPrimesCount + c;
                    nonPrimesCount += c;
                }
            }
        }

        return res;
    }
};