class SegmentTree{
private:
    const int N;
    vector<pair<int, int>> tree;

    void buildTree(int node, int l, int r, const vector<pair<int, int>>& VALUES){
        if(l == r){
            tree[node] = VALUES[r];
        }else{
            int mid = (l + r) / 2;
            buildTree(2 * node + 1, l, mid, VALUES);
            buildTree(2 * node + 2, mid + 1, r, VALUES);
            tree[node] = min(tree[2 * node + 1], tree[2 * node + 2]);
        }
    }

    pair<int, int> getMin(int node, int l, int r, const int L, const int R){
        if(R < l || r < L){
            return {INT_MAX, INT_MAX};
        }
        if(L <= l && r <= R){
            return tree[node];
        }
        int mid = (l + r) / 2;
        return min(getMin(2 * node + 1, l, mid, L, R),
                   getMin(2 * node + 2, mid + 1, r, L, R));
    }

public:
    SegmentTree(const vector<pair<int, int>>& VALUES): N(VALUES.size()){
        int minLeaves = 1;
        while(minLeaves < N){
            minLeaves *= 2;
        }
        tree.assign(2 * minLeaves, {INT_MAX, INT_MAX});
        buildTree(0, 0, N - 1, VALUES);
    }

    pair<int, int> getMin(const int L, const int R){
        return getMin(0, 0, N - 1, L, R);
    }
};

class Solution {
private:
    using Graph = vector<vector<int>>;

    void eulerTour(int level, int parent, int node, const Graph& G, vector<int>& levelOf, vector<pair<int, int>>& eln){
        levelOf[node] = level;
        eln.push_back({level, node});
        for(int nextNode: G[node]){
            if(nextNode != parent){
                eulerTour(level + 1, node, nextNode, G, levelOf, eln);
                eln.push_back({level, node});
            }
        }
    }

    int getLCA(int a, int b, SegmentTree& tree, vector<int>& firstPosOf){
        int l = min(firstPosOf[a], firstPosOf[b]);
        int r = max(firstPosOf[a], firstPosOf[b]);
        return tree.getMin(l, r).second;
    }

public:
    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        const int Q = queries.size();
        const int E = edges.size();
        const int N = E + 1;
        const int MODULO = 1'000'000'007;

        Graph G(N + 1);
        for(vector<int>& edge: edges){
            int a = edge[0];
            int b = edge[1];
            G[a].push_back(b);
            G[b].push_back(a);
        }

        vector<int> levelOf(N + 1);
        vector<pair<int, int>> eln;
        eulerTour(1, -1, 1, G, levelOf, eln);

        SegmentTree tree(eln);

        vector<int> firstPosOf(N + 1, -1);
        for(int i = 0; i < (int)eln.size(); ++i){
            int node = eln[i].second;
            if(firstPosOf[node] == -1){
                firstPosOf[node] = i;
            }
        }

        vector<int> pow2(N + 1, 1);
        for(int i = 1; i <= N; ++i){
            pow2[i] = 2 * pow2[i - 1] % MODULO;
        }

        vector<int> res(Q);
        for(int qIdx = 0; qIdx < Q; ++qIdx){
            int a = queries[qIdx][0];
            int b = queries[qIdx][1];
            if(a == b){
                continue;
            }
            int abLCA = getLCA(a, b, tree, firstPosOf);
            int abDist = levelOf[a] + levelOf[b] - 2 * levelOf[abLCA];
            res[qIdx] = pow2[abDist - 1];
        }

        return res;
    }
};