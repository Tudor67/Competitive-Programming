class SegmentTree{
private:
    const int N;
    vector<int> tree;

    void add(int node, int l, int r, const int POS, const int VAL){
        if(l == r){
            tree[node] += VAL;
        }else{
            int mid = (l + r) / 2;
            if(POS <= mid){
                add(2 * node + 1, l, mid, POS, VAL);
            }else{
                add(2 * node + 2, mid + 1, r, POS, VAL);
            }
            tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
        }
    }

    int query(int node, int l, int r, const int L, const int R){
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
    }

    void add(const int POS, const int VAL){
        add(0, 0, N - 1, POS, VAL);
    }

    int computePrefixSum(const int R){
        return query(0, 0, N - 1, 0, R);
    }
};

class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        const int F = flowers.size();
        const int P = people.size();

        // Coordinate compression
        vector<int> sortedValues;
        for(int i = 0; i < F; ++i){
            sortedValues.push_back(flowers[i][0]);
            sortedValues.push_back(flowers[i][1]);
        }

        for(int i = 0; i < P; ++i){
            sortedValues.push_back(people[i]);
        }

        sort(sortedValues.begin(), sortedValues.end());
        sortedValues.resize(unique(sortedValues.begin(), sortedValues.end()) - sortedValues.begin());

        // Build the `res` vector using a SegmentTree on compressed values
        SegmentTree tree(sortedValues.size() + 1);
        for(int i = 0; i < F; ++i){
            int l = lower_bound(sortedValues.begin(), sortedValues.end(), flowers[i][0]) - sortedValues.begin();
            int r = lower_bound(sortedValues.begin(), sortedValues.end(), flowers[i][1]) - sortedValues.begin();
            tree.add(l, 1);
            tree.add(r + 1, -1);
        }

        vector<int> res(P);
        for(int i = 0; i < P; ++i){
            int compressedVal = lower_bound(sortedValues.begin(), sortedValues.end(), people[i]) - sortedValues.begin();
            res[i] = tree.computePrefixSum(compressedVal);
        }

        return res;
    }
};