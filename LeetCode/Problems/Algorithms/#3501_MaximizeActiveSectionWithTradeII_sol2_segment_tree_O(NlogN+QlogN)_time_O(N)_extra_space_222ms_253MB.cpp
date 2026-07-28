class SegmentTree{
private:
    const int N;
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
            tree[node] = max(tree[2 * node + 1], tree[2 * node + 2]);
        }
    }

    int getMax(int node, int l, int r, const int L, const int R){
        if(R < l || r < L){
            return 0;
        }
        if(L <= l && r <= R){
            return tree[node];
        }
        int mid = (l + r) / 2;
        return max(getMax(2 * node + 1, l, mid, L, R),
                   getMax(2 * node + 2, mid + 1, r, L, R));
    }

public:
    SegmentTree(const int N): N(N){
        int minLeaves = 1;
        while(minLeaves < N){
            minLeaves *= 2;
        }
        tree.assign(2 * minLeaves, 0);
    }

    void update(const int POS, const int VAL){
        update(0, 0, N - 1, POS, VAL);
    }

    int getMax(const int L, const int R){
        if(L > R){
            return 0;
        }
        return getMax(0, 0, N - 1, L, R);
    }
};

class Solution {
public:
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
        const int N = s.length();
        const int INITIAL_ONES = count(s.begin(), s.end(), '1');
        const int Q = queries.size();

        vector<int> zeros;
        vector<int> starts;
        int currZeros = 0;
        for(int i = 0; i < N; ++i){
            if(s[i] == '0'){
                currZeros += 1;
                if(i + 1 == N || s[i + 1] == '1'){
                    zeros.push_back(currZeros);
                    starts.push_back(i - currZeros + 1);
                    currZeros = 0;
                }
            }
        }

        SegmentTree tree((int)zeros.size());
        for(int i = 0; i + 1 < (int)zeros.size(); ++i){
            tree.update(i, zeros[i] + zeros[i + 1]);
        }

        vector<int> res(Q);
        for(int qIdx = 0; qIdx < Q; ++qIdx){
            int l = queries[qIdx][0];
            int r = queries[qIdx][1];

            int ll = lower_bound(starts.begin(), starts.end(), l) - starts.begin();
            int rr = upper_bound(starts.begin(), starts.end(), r) - starts.begin() - 1;
            while(ll <= rr && starts[rr] + zeros[rr] - 1 > r){
                rr -= 1;
            }

            int maxGain = tree.getMax(ll, rr - 1);
            for(int i: {ll - 1, rr}){
                if(0 <= i && i + 1 < (int)starts.size() &&
                   l <= starts[i] + zeros[i] - 1 && starts[i + 1] <= r){
                    int currGain = zeros[i] - max(0, l - starts[i]) +
                                   zeros[i + 1] - max(0, (starts[i + 1] + zeros[i + 1] - 1) - r);
                    maxGain = max(maxGain, currGain);
                }
            }

            res[qIdx] = INITIAL_ONES + maxGain;
        }

        return res;
    }
};