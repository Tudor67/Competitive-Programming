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

    int getSum(int node, int l, int r, const int L, const int R){
        if(R < l || r < L){
            return 0;
        }
        if(L <= l && r <= R){
            return tree[node];
        }
        int mid = (l + r) / 2;
        return getSum(2 * node + 1, l, mid, L, R) +
               getSum(2 * node + 2, mid + 1, r, L, R);
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

    int getSum(const int L, const int R){
        if(L > R){
            return 0;
        }
        return getSum(0, 0, N - 1, L, R);
    }
};

class Solution {
public:
    int numTeams(vector<int>& rating) {
        const int N = rating.size();

        vector<int> sortedRatings = rating;
        sort(sortedRatings.begin(), sortedRatings.end());

        SegmentTree leftTree(N);
        SegmentTree rightTree(N);
        for(int i = 0; i < N; ++i){
            rightTree.add(i, 1);
        }

        int validTeams = 0;
        for(int j = 0; j < N - 1; ++j){
            int compressedRating = lower_bound(sortedRatings.begin(), sortedRatings.end(), rating[j])
                                   - sortedRatings.begin();
            
            leftTree.add(compressedRating, 1);
            rightTree.add(compressedRating, -1);

            int leftSize = j;
            int leftSmallerCount = leftTree.getSum(0, compressedRating - 1);

            int rightSize = N - 1 - j;
            int rightGreaterCount = rightTree.getSum(compressedRating + 1, N - 1);

            validTeams += leftSmallerCount * rightGreaterCount;
            validTeams += (leftSize - leftSmallerCount) * (rightSize - rightGreaterCount);
        }

        return validTeams;
    }
};