class SegmentTree{
private:
    const int N;
    const int K;
    vector<int> prod;
    vector<vector<int>> count;

    void update(int node, int l, int r, const int POS, const int VAL){
        if(l == r){
            count[node][prod[node]] = 0;
            prod[node] = VAL % K;
            count[node][prod[node]] = 1;
        }else{
            int mid = (l + r) / 2;
            if(POS <= mid){
                update(2 * node + 1, l, mid, POS, VAL);
            }else{
                update(2 * node + 2, mid + 1, r, POS, VAL);
            }

            prod[node] = prod[2 * node + 1] * prod[2 * node + 2] % K;
            count[node] = count[2 * node + 1];
            for(int rem = 0; rem < K; ++rem){
                count[node][prod[2 * node + 1] * rem % K] += count[2 * node + 2][rem];
            }
        }
    }

    void query(int node, int l, int r, const int L, const int R, vector<int>& res, int& resProd){
        if(R < l || r < L){
            // ignore
        }else if(L <= l && r <= R){
            for(int rem = 0; rem < K; ++rem){
                res[resProd * rem % K] += count[node][rem];
            }
            resProd = resProd * prod[node] % K;
        }else{
            int mid = (l + r) / 2;
            query(2 * node + 1, l, mid, L, R, res, resProd);
            query(2 * node + 2, mid + 1, r, L, R, res, resProd);
        }
    }

public:
    SegmentTree(const int N, const int K): N(N), K(K) {
        int minLeaves = 1;
        while(minLeaves < N){
            minLeaves *= 2;
        }
        prod.assign(2 * minLeaves, {});
        count.assign(2 * minLeaves, vector<int>(K, 0));
    }

    void update(const int POS, const int VAL){
        update(0, 0, N - 1, POS, VAL);
    }

    int query(const int L, const int R, const int X){
        vector<int> res(K);
        int resProd = 1;
        query(0, 0, N - 1, L, R, res, resProd);
        return res[X];
    }
};

class Solution {
public:
    vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) {
        const int N = nums.size();
        const int Q = queries.size();

        SegmentTree tree(N, k);
        for(int i = 0; i < N; ++i){
            tree.update(i, nums[i]);
        }

        vector<int> res(Q);
        for(int queryIndex = 0; queryIndex < Q; ++queryIndex){
            int index = queries[queryIndex][0];
            int value = queries[queryIndex][1];
            int start = queries[queryIndex][2];
            int x = queries[queryIndex][3];

            tree.update(index, value);
            res[queryIndex] = tree.query(start, N - 1, x);
        }

        return res;
    }
};