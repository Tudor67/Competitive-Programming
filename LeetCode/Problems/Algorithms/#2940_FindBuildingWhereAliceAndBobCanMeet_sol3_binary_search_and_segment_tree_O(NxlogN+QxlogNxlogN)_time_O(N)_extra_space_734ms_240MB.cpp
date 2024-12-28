class SegmentTree{
private:
    const int N;
    vector<int> tree;

    void update(int node, int l, int r, const int POS, const int VAL){
        if(l == r){
            tree[node] = max(tree[node], VAL);
        }else{
            int mid = (l + r) / 2;
            if(POS <= mid){
                update(2 * node + 1, l, mid, POS, VAL);
            }else{
                update(2 * node + 2, mid + 1, r, POS, VAL);
            }
            tree[node] = max(tree[2 * node + 1], tree[2 * node + 2]);
        }
    }

    int computeMax(int node, int l, int r, const int L, const int R){
        if(R < l || r < L){
            return 0;
        }
        if(L <= l && r <= R){
            return tree[node];
        }
        int mid = (l + r) / 2;
        return max(computeMax(2 * node + 1, l, mid, L, R),
                   computeMax(2 * node + 2, mid + 1, r, L, R));
    }

public:
    SegmentTree(const int N): N(N){
        int minLeaves = 1;
        while(minLeaves < N){
            minLeaves *= 2;
        }
        tree.resize(2 * minLeaves);
    }

    void update(const int POS, const int VAL){
        update(0, 0, N - 1, POS, VAL);
    }

    int computeMax(const int L, const int R){
        if(L > R){
            return 0;
        }
        return computeMax(0, 0, N - 1, L, R);
    }
};

class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        const int N = heights.size();
        const int Q = queries.size();

        SegmentTree tree(N);
        for(int i = 0; i < N; ++i){
            tree.update(i, heights[i]);
        }

        vector<int> res(Q, -1);
        for(int queryIndex = 0; queryIndex < Q; ++queryIndex){
            int a = queries[queryIndex][0];
            int b = queries[queryIndex][1];

            if(a > b){
                swap(a, b);
            }

            if(a == b || heights[a] < heights[b]){
                res[queryIndex] = b;
            }else{
                int threshold = heights[a] + 1;
                int startIndex = b + 1;
                int l = startIndex;
                int r = N;
                while(l != r){
                    int mid = (l + r) / 2;
                    if(threshold <= tree.computeMax(startIndex, mid)){
                        r = mid;
                    }else{
                        l = mid + 1;
                    }
                }

                if(r < N && threshold <= heights[r]){
                    res[queryIndex] = r;
                }
            }
        }

        return res;
    }
};