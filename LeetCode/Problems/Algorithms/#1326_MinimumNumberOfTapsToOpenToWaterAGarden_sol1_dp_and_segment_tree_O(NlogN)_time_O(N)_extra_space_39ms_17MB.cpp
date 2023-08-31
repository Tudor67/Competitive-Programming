class SegmentTree{
private:
    const int N;
    const int INF;
    vector<int> tree;

    void update(int node, int l, int r, const int POS, const int VAL){
        if(l == r){
            tree[node] = VAL;
        }else{
            int mid = (l + r) / 2;
            if(POS <= mid){
                update(2 * node + 1, l, mid, POS, VAL);
            }else{
                update(2 * node + 2, mid + 1, r, POS, VAL);
            }
            tree[node] = min(tree[2 * node + 1], tree[2 * node + 2]);
        }
    }

    int query(int node, int l, int r, const int L, const int R){
        if(r < L || R < l){
            return INF;
        }
        if(L <= l && r <= R){
            return tree[node];
        }
        int mid = (l + r) / 2;
        return min(query(2 * node + 1, l, mid, L, R),
                   query(2 * node + 2, mid + 1, r, L, R));
    }

public:
    SegmentTree(const int N, const int INF): N(N), INF(INF){
        int minLeaves = 1;
        while(minLeaves < N){
            minLeaves *= 2;
        }
        tree.resize(2 * minLeaves, INF);
    }

    void update(const int POS, const int VAL){
        update(0, 0, N - 1, POS, VAL);
    }

    int query(const int L, const int R){
        if(L > R){
            return INF;
        }
        return query(0, 0, N - 1, L, R);
    }
};

class Solution {
public:
    int minTaps(int N, vector<int>& ranges) {
        using Segment = pair<int, int>;
        const int INF = 1e9;

        vector<Segment> sortedSegments(N + 1);
        for(int i = 0; i < N + 1; ++i){
            sortedSegments[i] = {max(0, i - ranges[i]), min(N, i + ranges[i])};
        }

        sort(sortedSegments.begin(), sortedSegments.end());

        // dp[i]: min cost to water the range [sortedSegments[i].first .. N]
        vector<int> dp(N + 1, INF);
        SegmentTree segmentTree(N + 1, INF);

        for(int i = N; i >= 0; --i){
            if(sortedSegments[i].second == N){
                dp[i] = 1;
            }else{
                int j = upper_bound(sortedSegments.begin() + i, sortedSegments.end(), pair<int, int>{sortedSegments[i].second, INF})
                                    - sortedSegments.begin() - 1;
                dp[i] = min(dp[i], 1 + segmentTree.query(i + 1, j));
            }
            if(i + 1 <= N && sortedSegments[i].first == sortedSegments[i + 1].first){
                dp[i] = min(dp[i], dp[i + 1]);
            }
            segmentTree.update(i, dp[i]);
        }

        if(sortedSegments[0].first == 0 && dp[0] != INF){
            return dp[0];
        }

        return -1;
    }
};