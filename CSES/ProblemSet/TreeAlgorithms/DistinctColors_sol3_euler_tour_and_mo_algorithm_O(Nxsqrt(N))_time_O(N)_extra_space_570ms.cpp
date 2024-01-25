#include <bits/stdc++.h>
using namespace std;

using Graph = vector<vector<int>>;

class GraphTraversal{
public:
    void eulerTour(int parent, int node, vector<int>& eulerNodes, const Graph& G){
        eulerNodes.push_back(node);
        for(int nextNode: G[node]){
            if(nextNode != parent){
                eulerTour(node, nextNode, eulerNodes, G);
                eulerNodes.push_back(node);
            }
        }
    }
};

class MoAlgorithm{
private:
    const int N;
    const int SQRT_N;
    const vector<int>& V;
    int distinctValues;
    vector<int> f;
    vector<int> p;

public:
    MoAlgorithm(const vector<int>& V): N(V.size()), SQRT_N(sqrt(N)), V(V){

    }

    void add(int idx){
        f[V[idx]] += 1;
        distinctValues += (int)(f[V[idx]] == 1);
    }

    void remove(int idx){
        f[V[idx]] -= 1;
        distinctValues -= (int)(f[V[idx]] == 0);
    }

    int getResult(){
        return distinctValues;
    }

    void solve(vector<pair<int, int>>& queries, vector<int>& res){
        const int Q = queries.size();

        res.resize(Q);

        distinctValues = 0;
        f.resize(N);
        fill(f.begin(), f.end(), 0);

        p.resize(Q);
        iota(p.begin(), p.end(), 0);
        sort(p.begin(), p.end(),
             [&](int lhs, int rhs){
                return pair<int, int>{queries[lhs].first / SQRT_N, queries[lhs].second} <
                       pair<int, int>{queries[rhs].first / SQRT_N, queries[rhs].second};
             });

        int l = 0;
        int r = -1;
        for(const int Q_IDX: p){
            const int Q_L = queries[Q_IDX].first;
            const int Q_R = queries[Q_IDX].second;

            while(r + 1 <= Q_R){
                add(r + 1);
                r += 1;
            }
            while(l < Q_L){
                remove(l);
                l += 1;
            }
            while(Q_R < r){
                remove(r);
                r -= 1;
            }
            while(Q_L < l){
                add(l - 1);
                l -= 1;
            }

            res[Q_IDX] = getResult();
        }
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Read and build Graph G (G is a tree)
    int N;
    cin >> N;

    vector<int> C(N);
    for(int i = 0; i < N; ++i){
        cin >> C[i];
    }

    Graph G(N);
    for(int i = 1; i <= N - 1; ++i){
        int a, b;
        cin >> a >> b;
        a -= 1;
        b -= 1;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    // Coordinate Compression for input colors
    vector<int> sortedColors = C;
    sort(sortedColors.begin(), sortedColors.end());
    sortedColors.resize(unique(sortedColors.begin(), sortedColors.end()) - sortedColors.begin());

    for(int i = 0; i < N; ++i){
        C[i] = lower_bound(sortedColors.begin(), sortedColors.end(), C[i]) - sortedColors.begin();
    }

    // Euler Tour of G
    vector<int> eulerNodes;
    GraphTraversal().eulerTour(-1, 0, eulerNodes, G);

    vector<int> eulerColors(eulerNodes.size());
    for(int i = 0; i < (int)eulerNodes.size(); ++i){
        eulerColors[i] = C[eulerNodes[i]];
    }
    
    // Compute first and last index of each node in the eulerNodes vector
    vector<int> firstPos(N, -1);
    vector<int> lastPos(N);
    for(int i = 0; i < (int)eulerNodes.size(); ++i){
        int node = eulerNodes[i];
        if(firstPos[node] == -1){
            firstPos[node] = i;
        }
        lastPos[node] = i;
    }

    // Computing the number of distinct colors in the subtree of node
    // is the same as computing the number of distinct values
    // in the range [firstPos[node] .. lastPos[node]] of eulerColors vector
    // To solve all queries {[firstPos[0] .. lastPos[0]], [firstPos[1] .. lastPos[1]], ..}
    // we can use Mo's Algorithm
    vector<pair<int, int>> queries(N);
    for(int node = 0; node < N; ++node){
        queries[node] = {firstPos[node], lastPos[node]};
    }

    vector<int> res;
    MoAlgorithm(eulerColors).solve(queries, res);

    for(int node = 0; node < N; ++node){
        cout << res[node] << " ";
    }

    return 0;
}