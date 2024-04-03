class SegmentTree{
private:
    const int N;
    vector<long long> tree;
    vector<int> lazy;

    void propagate(int node, int l, int r){
        tree[node] += lazy[node] * (long long)(r - l + 1);
        if(l != r){
            lazy[2 * node + 1] += lazy[node];
            lazy[2 * node + 2] += lazy[node];
        }
        lazy[node] = 0;
    }

    void add(int node, int l, int r, const int L, const int R, const int VAL){
        propagate(node, l, r);
        if(r < L || R < l){
            // stop
        }else if(L <= l && r <= R){
            lazy[node] += VAL;
            propagate(node, l, r);
        }else{
            int mid = (l + r) / 2;
            add(2 * node + 1, l, mid, L, R, VAL);
            add(2 * node + 2, mid + 1, r, L, R, VAL);
            tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
        }
    }

    long long query(int node, int l, int r, const int L, const int R){
        propagate(node, l, r);
        if(r < L || R < l){
            return 0;
        }
        if(L <= l && r <= R){
            return tree[node];
        }
        int mid = (l + r) / 2;
        return query(2 * node + 1, l, mid, L, R) +
               query(2 * node + 2, mid + 1, r, L, R);
    }

public:
    SegmentTree(const int N): N(N){
        int minLeaves = 1;
        while(minLeaves < N){
            minLeaves *= 2;
        }
        tree.resize(2 * minLeaves);
        lazy.resize(2 * minLeaves);
    }

    long long query(const int L, const int R){
        if(L > R){
            return 0;
        }
        return query(0, 0, N - 1, L, R);
    }

    void add(const int L, const int R, const int VAL){
        if(L > R){
            return;
        }
        add(0, 0, N - 1, L, R, VAL);
    }
};

class Solution {
public:
    int sumCounts(vector<int>& nums) {
        const int N = nums.size();
        const long long MODULO = 1e9 + 7;

        long long res = 0;
        long long sum2 = 0;
        unordered_map<int, int> lastIndexOf;
        SegmentTree tree(N);

        for(int i = 0; i < N; ++i){
            if(!lastIndexOf.count(nums[i])){
                lastIndexOf[nums[i]] = -1;
            }

            long long sum1 = tree.query(lastIndexOf[nums[i]] + 1, i - 1);
            sum2 += 2 * sum1;
            sum2 += i - lastIndexOf[nums[i]] - 1;
            sum2 += 1;
            sum2 %= MODULO;

            res += sum2;
            res %= MODULO;

            tree.add(lastIndexOf[nums[i]] + 1, i, 1);
            lastIndexOf[nums[i]] = i;
        }

        return res;
    }
};