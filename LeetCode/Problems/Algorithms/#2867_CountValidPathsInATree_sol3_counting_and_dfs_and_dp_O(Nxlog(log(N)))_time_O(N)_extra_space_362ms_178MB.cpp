class Solution {
private:
    using Graph = vector<vector<int>>;

    pair<long long, long long> dfs(int parent, int node, vector<bool>& isPrime, const Graph& G, long long& res){
        long long s0 = 0;
        long long s1 = 0;

        for(int child: G[node]){
            if(child != parent){
                pair<long long, long long> p = dfs(node, child, isPrime, G, res);
                long long c0 = p.first;
                long long c1 = p.second;

                if(isPrime[node]){
                    res += s0 * c0 + c0;
                }else{
                    res += s1 * c0 + s0 * c1 + c1;
                }

                s0 += c0;
                s1 += c1;
            }
        }

        if(isPrime[node]){
            return {0, s0 + 1};
        }
        return {s0 + 1, s1};
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

        long long res = 0;
        dfs(-1, 1, isPrime, G, res);

        return res;
    }
};